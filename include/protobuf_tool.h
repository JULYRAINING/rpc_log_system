/**
*
* @file		proto_buffer_tool.h
* @author	SHIBO
* @date		2017/7/7
* @version 	1.1
* @brief	服务器端 ProtoBuffer解析类
*           
*/

#ifndef RPCLOGSYSTEM_INCLUDE_PROTO_BUFFER_TOOL_H
#define RPCLOGSYSTEM_INCLUDE_PROTO_BUFFER_TOOL_H

#include <stdio.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include "logger.h"

namespace log_system_server{
class ProtoBufferTool{
public:
    ProtoBufferTool();
    ~ProtoBufferTool();
    /* 
                @description 根据type_name创建Message类型
                @param type_name Message的包名加Message的name
                */
    google::protobuf::Message* createMessage(const std::string& type_name);
    
   
private:
    //系统日志操作类
    system_log::Logger* _logger;
};
}

#endif //RPCLOGSYSTEM_INCLUDE_PROTO_BUFFER_TOOL_H