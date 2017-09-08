/**
*
* @file		process.h
* @author	SHIBO
* @date		2017/7/7
* @version 	1.1
* @brief	服务器端 日志处理类
*           
*/

#ifndef RPCLOGSYSTEM_INCLUDE_PROCESS_H
#define RPCLOGSYSTEM_INCLUDE_PROCESS_H

#include <iostream>

#include <string>

#include <vector>
#include <iterator>

#include <google/protobuf/text_format.h>

#include "log.pb.h"
#include "process_interface.h"
#include "log_buffer.h"
#include "logger.h"
#include "protobuf_tool.h"

namespace logsystem_process
{

class Process : public logsystem_process::ProcessInterface
{
public:
  //构造函数
  Process();

  ~Process();

  /* 
                @description 构造函数
                @param path 日志存储路径
                */
  Process(std::string path);

  /* 
                @description 日志处理方法
                @param message 日志消息
                */
  int process_msg(std::string message);

private:
  //Protobuf操作类
  log_system_server::ProtoBufferTool protobuf_tool;
  //系统日志操作类
  system_log::Logger *_logger;
  //日志文件目录
  std::string _log_path;

  //缓冲类
  logsystem_buffer::LogBuffer _buffer;
};
}

#endif //RPCLOGSYSTEM_INCLUDE_PROCESS_H