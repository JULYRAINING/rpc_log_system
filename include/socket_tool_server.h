/**
*
* @file		socket_tool_server.h
* @author	SHIBO
* @date		2017/7/7
* @version 	1.1
* @brief	服务器端 Socket连接类
*           
*/

#ifndef RPCLOGSYSTEM_INCLUDE_SOCKET_TOOL_SERVER_H
#define RPCLOGSYSTEM_INCLUDE_SOCKET_TOOL_SERVER_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>
// #include <Winsock2.h>
#include <sys/socket.h>
#include <thread>
#include <sys/time.h>
#include <google/protobuf/text_format.h>
#include "log.pb.h"
#include "protobuf_tool.h"
#include "mq.h"
#include "logger.h"


namespace log_system_server{
class SocketToolServer{
public:
    SocketToolServer();
    ~SocketToolServer();
    /* 
    @description 初始化SocketTool中的ip和port
    @param ip_l ip地址
    @param port_l port端口
    */
    SocketToolServer(std::string ip, int port); 
    //监听客户端请求。
    int listen_client();     
    //处理
    int handle(int serv_sock, std::string client_ip, int port);
    //开启线程监听客户端
    int listening();
      
    //断开连接       
    int disconnect();                              
    
private:
    //消息队列处理类
    logsystem_messagequeue::MessageQueueTool *message_queue_tool_send;
    //开始时间
    long long begin_time;
    //接受消息数
    static int _s_number_of_message;
    //系统日志类
    system_log::Logger* _logger;
    //初始化Socket连接
    int init();      
    //ip             
    std::string _ip;             
    //port  
    int _port;      
    //socket连接               
    int _serv_sock;        
    //socket连接        
    int _clnt_sock;   
      
    //地址结构       
    struct sockaddr_in _serv_addr; 
    
    //protobuf
    google::protobuf::Message *new_message;
};
}

#endif //RPCLOGSYSTEM_INCLUDE_SOCKET_TOOL_SERVER_H