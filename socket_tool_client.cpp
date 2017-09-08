/**
*
* @file		socket_tool_client.h
* @author	SHIBO
* @date		2017/7/7
* @version 	1.1
* @brief	客户端 Socket连接类
*           
*/

#include "include/socket_tool_client.h"

namespace log_system_client
{
int SocketToolClient::_write_flag = 0;
int SocketToolClient::_s_number_of_message = 0;
int SocketToolClient::_s_number_of_message_per_sec = 0;
std::string SocketToolClient::_log_path = "/local_log";
std::string SocketToolClient::_log_filename = "local";

SocketToolClient::SocketToolClient()
{
    LOG_DEBUG("创建SocketToolClient");
}
SocketToolClient::~SocketToolClient()
{
    LOG_DEBUG("销毁SocketToolClient");
}

SocketToolClient::SocketToolClient(std::string ip, int port)
{
    _ip = ip;
    _port = port;
    LOG_DEBUG("创建SocketToolClient");
}

int SocketToolClient::set_options(std::string ip, int port)
{
    _ip = ip;
    _port = port;
}
int SocketToolClient::connection()
{

    init();
    LOG_DEBUG("开始连接服务器");
    int result = connect(_sock, (struct sockaddr *)&_serv_addr, sizeof(_serv_addr));

    if (result != 0)
    {
        LOG_ERROR("服务器连接失败");
        reconnection();
    }
    else
    {
        LOG_DEBUG("服务器已连接");
        return 0;
    }
}
int SocketToolClient::reconnection()
{
    LOG_DEBUG("尝试重新连接服务器...");
    int attempt_time = 0;
    int result = -1;
    while (result != 0 && attempt_time < 3)
    {
        result = connect(_sock, (struct sockaddr *)&_serv_addr, sizeof(_serv_addr));
        ++attempt_time;
        LOG_DEBUG("尝试第 " + std::to_string(attempt_time) + " 次...");
    }
    if (result != 0)
    {
        LOG_DEBUG("3次尝试连接失败，日志将会写入本地");
        _write_flag = 1;
    }
    else
    {
        LOG_DEBUG("服务器重连成功");
        return 0;
    }
}

int SocketToolClient::writing_str(std::string message)
{
    //日志存储目录
    std::string write_path = _log_path;
    //日志存储文件
    std::string write_filename = _log_filename;
    char str[1024];
    strncpy(str, message.c_str(), sizeof(str));
    str[sizeof(str) - 1] = 0;
    if (_write_flag == 0)
    {
        int result = 0;
        //写入服务器
        try
        {
            LOG_TRACE("发送日志到服务器");

            result = write(_sock, str, sizeof(str));
            LOG_TRACE("" + std::to_string(result) + "");

            if (result == -1)
            {
                LOG_ERROR("数据发送失败");
            }
            else
            {
                LOG_TRACE("发送完毕");
            }
        }
        catch (...)
        {
            LOG_ERROR("数据发送失败");
        }

        if (result != 0)
        {
            LOG_TRACE("数据发送成功");
        }
        else
        {
            LOG_DEBUG("向服务器写入数据失败，写入本地文件");
            _buffer.write(message, write_path, write_filename);
        }
    }
    else
    {
        LOG_DEBUG("无法连接服务器，日志将写入本地文件");
        _buffer.write(message, write_path, write_filename);
    }

    return 0;
}

int SocketToolClient::writing(google::protobuf::Message *message, std::string messagetype)
{

    std::string sendData;

    message->SerializeToString(&sendData);

    sendData = messagetype + "|" + sendData;

    char str[1024];
    strncpy(str, sendData.c_str(), sizeof(str));
    str[sizeof(str) - 1] = 0;

    if (_write_flag == 0)
    {
        int result = 0;
        //写入服务器
        try
        {
            LOG_DEBUG("发送日志到服务器");

            result = write(_sock, str, sizeof(str));
            struct timeval current_tp;
            gettimeofday(&current_tp, NULL);
            long long current_time = (long long)current_tp.tv_sec * 1000L + current_tp.tv_usec / 1000;
            ++_s_number_of_message_per_sec;
            ++_s_number_of_message;
            if (current_time - begin_time >= 1000)
            {
                LOG_FATAL(" " + std::to_string(_s_number_of_message_per_sec) + "");
                _s_number_of_message_per_sec = 0;
                begin_time = current_time;
            }
            // LOG_TRACE("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`" + str +"")
            LOG_TRACE("发送完毕");
        }
        catch (...)
        {
            LOG_TRACE("数据发送失败");
        }

        if (result != 0)
        {
            LOG_TRACE("数据发送成功");
        }
        else
        {
            LOG_TRACE("向服务器写入数据失败，写入本地文件");

            write_to_local(message);
        }
    }
    else
    {
        LOG_TRACE("无法连接服务器，日志将写入本地文件");
        write_to_local(message);
    }

    return 0;
}
int SocketToolClient::init()
{

    struct timeval begin_tp;
    gettimeofday(&begin_tp, NULL);
    begin_time = (long long)begin_tp.tv_sec * 1000L + begin_tp.tv_usec / 1000;

    LOG_TRACE("开始初始化服务器监听程序");
    //创建套接字
    _sock = socket(AF_INET, SOCK_STREAM, 0);
    //向服务器（特定的IP和端口）发起请求

    memset(&_serv_addr, 0, sizeof(_serv_addr));          //每个字节都用0填充
    _serv_addr.sin_family = AF_INET;                     //使用IPv4地址
    _serv_addr.sin_addr.s_addr = inet_addr(_ip.c_str()); //具体的IP地址
    _serv_addr.sin_port = htons(_port);                  //端口
    LOG_TRACE("服务器监听程序初始化完成");
    return 0;
}

int SocketToolClient::write_to_local(google::protobuf::Message *message)
{
    /*

    本地存储无需按类别区分，可以直接存储到同一个文件
    //获取描述符
    const google::protobuf::Descriptor *descriptor = message->GetDescriptor();
    //获取字段描述符
    const google::protobuf::FieldDescriptor *field = descriptor->FindFieldByName("unique_name");
    //protobuf package.Message
    std::string unique_name;
    */
    //message 字符串
    std::string message_string;

    //将message信息转为string
    google::protobuf::TextFormat::Printer printer;
    printer.SetSingleLineMode(true);
    // printer.PrintFieldValueToString(*message, field, -1, &unique_name);
    printer.PrintToString(*message, &message_string);
    /*
    // 前后有引号，删除
    unique_name = unique_name.substr(1, unique_name.length() - 2);

    // 定义目录（细化目录）
    std::vector<std::string> file_paths = _buffer.split(unique_name, '.');
    
    std::string write_path = _log_path + "/" + file_paths[0];

    std::string _log_filename = file_paths[1] + ".log";
    */
    std::string write_path = _log_path;
    std::string write_filename = _log_filename;
    _buffer.write(message_string, write_path, write_filename);
    LOG_TRACE("缓冲区日志已写入文件");
}

int SocketToolClient::disconnect()
{
    close(_sock);
    LOG_TRACE("Socket连接已关闭");
}
}
