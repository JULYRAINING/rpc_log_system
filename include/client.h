/**
*
* @file		client.h
* @author	SHIBO
* @date		2017/7/7
* @version 	1.1
* @brief	客户端
*           
*/

#ifndef RPCLOGSYSTEM_INCLUDE_CLIENT_H
#define RPCLOGSYSTEM_INCLUDE_CLIENT_H

#include <unistd.h>
#include <iostream>
#include <thread>
#include <string.h>
#include "log.pb.h"
#include "socket_tool_client.h"
#include "logger.h"
#include "log_buffer.h"

namespace log_system_client
{

class Client
{
public:
	Client();
	/* 
		@description 构造方法
		@param ip ip地址
		@param port 端口号
		*/
	Client(std::string ip, int port);
	
	//启动客户端
	int run();
	log_system_client::SocketToolClient client;

private:
	//发送日志个数
	static int _s_send_log_count;
	//系统日志操作类
	system_log::Logger *_logger;
	//服务器ip
	std::string _ip;
	//服务器监听端口
	int _port;
	//发送日志到服务器
	int send();
	//读取本地文件，发送到服务器
	int polling();
};
}
#endif