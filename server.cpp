
#include "server.h"

namespace log_system_server
{

Server::Server(std::string ip, int port)
{
    _ip = ip;
    _port = port;
}

Server::~Server(){

}
int Server::run()
{

    log_system_server::SocketToolServer server(_ip, _port);
    server.listen_client();
    LOG_DEBUG("开始监听客户端连接...");
    logsystem_messagequeue::MessageQueueTool *message_queue_tool_consume = logsystem_messagequeue::MessageQueueTool::getInstance();
    LOG_DEBUG("创建日志处理类");
    logsystem_process::ProcessInterface *process = new logsystem_process::Process();
    LOG_DEBUG("开始轮询消息队列...");
    message_queue_tool_consume->consume_msg(process);
}
}