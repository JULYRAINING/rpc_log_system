/**
*
* @file		socket_tool_client.h
* @author	SHIBO
* @date		2017/7/7
* @version 	1.1
* @brief	客户端 Socket连接类
*           
*/

#ifndef RPCLOGSYSTEM_INCLUDE_SOCKET_TOOL_CLIENT_H
#define RPCLOGSYSTEM_INCLUDE_SOCKET_TOOL_CLIENT_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>
// #include <Winsock2.h>
#include <sys/socket.h>
#include <exception> 
#include <google/protobuf/text_format.h>
#include <sys/time.h>
#include "log.pb.h"
#include "log_buffer.h"
#include "logger.h"

namespace log_system_client{
class SocketToolClient{
public:
    SocketToolClient();
    //
    /* 
    @description 初始化SocketTool中的ip和port
    @param ip_l ip地址
    @param port_l port端口
    */
    SocketToolClient(std::string ip, int port); 
    /* 
    @description 设置SocketTool中的ip和port
    @param ip_l ip地址
    @param port_l port端口
    */
    int set_options(std::string ip, int port);
    //析构函数
    ~SocketToolClient();
     //连接服务器
    int connection();  
    //连接断开时重新连接                            
    int reconnection();     
    /* 
    @description 向服务器写入数据  
    @return message 日志消息
    */                     
    int writing(google::protobuf::Message* message, std::string messagetype);
        /* 
    @description 向服务器写入数据  
    @return message 日志消息字符串
    */                     
    int writing_str(std::string message);  
        
     //关闭连接                          
    int disconnect();                              
    
private:
    //time
    //开始时间
    long long begin_time;
    //发送消息数
    static int _s_number_of_message;
    //每秒发送消息数
    static int _s_number_of_message_per_sec;
    //系统日志操作类
    system_log::Logger* _logger;
    //日志存储路径
    static std::string _log_path;
    //日志文件名
    static std::string _log_filename;
    //标志日志写入位置，0-服务器， 1-本地
    static int _write_flag;
    //初始化Socket
    int init();   
    // ip地址                    
    std::string _ip;   
    // 端口号            
    int _port;  
    //套接字                  
    int _sock;    
    //地址结构                 
    struct sockaddr_in _serv_addr;

    //缓冲类
    logsystem_buffer::LogBuffer _buffer;
    //
    /* 
     @description 日志写入本地
     @param message 日志消息
     */
    int write_to_local(google::protobuf::Message* message);

};
}

#endif //RPCLOGSYSTEM_INCLUDE_SOCKET_TOOL_CLIENT_H