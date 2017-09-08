
#include "include/socket_tool_server.h"

namespace log_system_server
{

int SocketToolServer::_s_number_of_message = 0;

SocketToolServer::SocketToolServer()
{
    _ip = "127.0.0.1";
    _port = 1234;
}
SocketToolServer::~SocketToolServer()
{
    delete new_message;
    LOG_TRACE("结束监听");
}

SocketToolServer::SocketToolServer(std::string ip, int port)
{
    _ip = ip;
    _port = port;
    LOG_TRACE("创建SocketToolServer");
}

int SocketToolServer::listen_client()
{

    init();

    std::thread listening_thread(&SocketToolServer::listening, this);
    listening_thread.detach();
}

int SocketToolServer::listening()
{
    //接收客户端请求
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    int count;
    count = 0;
    while (true)
    {
        LOG_TRACE("等待客户端连接");
        _clnt_sock = accept(_serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
        //客户端ip
        std::string client_ip = inet_ntoa(clnt_addr.sin_addr);
        //客户端端口
        int port = (int)ntohs(clnt_addr.sin_port);
        LOG_TRACE("客户端已连接。IP地址：" + client_ip + "，端口号： " + std::to_string(port));

        std::thread handle_thread(&SocketToolServer::handle, this, _clnt_sock, client_ip, port);
        handle_thread.detach();
        LOG_TRACE("创建新线程处理来自 " + client_ip + " 的连接");
    }
    return 0;
}

int SocketToolServer::init()
{

    struct timeval begin_tp;
    gettimeofday(&begin_tp, NULL);
    begin_time = (long long)begin_tp.tv_sec * 1000L + begin_tp.tv_usec / 1000;

    message_queue_tool_send = logsystem_messagequeue::MessageQueueTool::getInstance();
    LOG_TRACE("开始初始化服务器监听程序");
    //创建套接字
    _serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //将套接字和IP、端口绑定

    memset(&_serv_addr, 0, sizeof(_serv_addr));          //每个字节都用0填充
    _serv_addr.sin_family = AF_INET;                     //使用IPv4地址
    _serv_addr.sin_addr.s_addr = inet_addr(_ip.c_str()); //具体的IP地址
    _serv_addr.sin_port = htons(_port);                  //端口
    bind(_serv_sock, (struct sockaddr *)&_serv_addr, sizeof(_serv_addr));
    listen(_serv_sock, 20);
    LOG_TRACE("服务器监听程序初始化完成");
}

int SocketToolServer::handle(int sock, std::string client_ip, int port)
{
    unsigned int microseconds;
    microseconds = 1000000;
    //每秒接受量
    int one_sec_count;
    while (true)
    {
        char buffer[2048];
        int result = read(sock, buffer, sizeof(buffer) - 1);

        if (result == 0)
        {

            LOG_DEBUG("客户端 " + client_ip + std::to_string(port) + " 无消息，等待中...");
            usleep(microseconds);
            continue;
        }
        //将buffer转化为字符串
        std::string str_data(buffer);

        LOG_DEBUG("read返回值: " + std::to_string(result));
        //统计接受数量

        struct timeval current_tp;
        gettimeofday(&current_tp, NULL);
        long long current_time = (long long)current_tp.tv_sec * 1000L + current_tp.tv_usec / 1000;
        int count = (++_s_number_of_message);
        ++one_sec_count;
        if (current_time - begin_time >= 1000)
        {
            LOG_FATAL(" " + std::to_string(one_sec_count) + "");
            one_sec_count = 0;
            begin_time = current_time;
           
            // LOG_FATAL("已接收：" + std::to_string(count) + "");
            // LOG_FATAL("开始时间: " + std::to_string(begin_time) + "");
            // LOG_FATAL("当前时间: " + std::to_string(current_time) + "");
            // LOG_FATAL("接收速率：" + std::to_string(count / (current_time - begin_time) / 1000) + "");
        }
        LOG_TRACE("已接收来自 " + client_ip + ":" + std::to_string(port) + " 的消息。");
        LOG_TRACE("来自 " + client_ip + ":" + std::to_string(port) + " 的消息已发送至消息队列");
        message_queue_tool_send->push_msg(str_data);
    }
}
}
