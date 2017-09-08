
/**
*
* @file		process_interface.h
* @author	SHIBO
* @date		2017/7/7
* @version 	1.1
* @brief	服务器端 消息处理抽象类
*           
*/
#ifndef RPCLOGSYSTEM_INCLUDE_PROCESS_INTERFACE_H
#define RPCLOGSYSTEM_INCLUDE_PROCESS_INTERFACE_H

#include "log.pb.h"

namespace logsystem_process{

class ProcessInterface{
    public:
        /* 
                @description 消息处理方法
                @param message 日志消息
                */
        virtual int process_msg(std::string message) = 0;
};
}

#endif //RPCLOGSYSTEM_INCLUDE_PROCESS_INTERFACE_H