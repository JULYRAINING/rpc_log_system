/**
*
* @file		server.h
* @author	SHIBO
* @date		2017/7/7
* @version 	1.1
* @brief	服务器端 启动服务器
*           
*/



#ifndef RPCLOGSYSTEM_SERVER_H
#define RPCLOGSYSTEM_SERVER_H



#include "socket_tool_server.h"
#include "mq.h"
#include "process.h"
#include "logger.h"

namespace log_system_server{

class Server{
    public:
    /* 
                @description 构造函数
                @param ip ip地址
                @param port 端口
                */
        Server(std::string ip, int port);
        /*
        启动服务器：1.监听客户端连接
                    2.启动消息队列
        */
        int run();

        ~Server();
        
    private:
        //系统日志操作类
        system_log::Logger* _logger;
        // ip地址
        std::string _ip;
        // 端口
        int _port;
};
}
#endif //RPCLOGSYSTEM_SERVER_H