/**
*
* @file		log_buffer.h
* @author	SHIBO
* @date		2017/7/7
* @version 	1.1
* @brief	日志缓冲类
*           
*/

#ifndef RPCLOGSYSTEM_INCLUDE_LOG_BUFFER_H
#define RPCLOGSYSTEM_INCLUDE_LOG_BUFFER_H

#include <iostream>

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <mutex>
#include <map>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "logger.h"
namespace logsystem_buffer
{
//缓冲类
class LogBuffer
{
public:
  LogBuffer();

  ~LogBuffer();

  /* 
                @description 构造方法
                @param buffer_size 缓冲区大小
                */
  explicit LogBuffer(int buffer_size);
  /* 
                @description 调用LogBuffer进行日志存储
                @param message 日志信息
                @param path 文件存储路径
                @param filename 文件名
                */
  int write(std::string message, std::string path, std::string filename);
  /* 
                @description 根据给定的字符分割字符串
                @param source 原字符串
                @param sep 切割字符
                @return 分割后的vector
                */
  std::vector<std::string> split(std::string source, char sep);

  /* 
                @description 从文件中读取日志
                @param path 日志路径
                @param filename 日志文件名
                @return 日志集合
                */
  std::vector<std::string> read(std::string path, std::string filename);
  //获得缓冲区大小
  int get_buffer_size();

private:

  //互斥信号量
  sem_t binSem;



  //系统日志操作类
  system_log::Logger *_logger;
  /* 
                @description 初始化目录,若不存在则创建
                @param path 日志文件路径
                */
  int init(std::string path);

  //缓冲区大小
  static int _max_buffer_size;
//缓冲区
  static std::map<std::string, std::vector<std::string> > _buffers;

  /* 
                @description 批量写入到文件
                @param path 日志文件路径
                @param filename 日志文件名
                */
  int write_to_file(std::string path, std::string filename);
  /* 
                @description 检查文件是否存在
                @param filename 日志文件名
                */
  bool isExistFile(std::string filename);
};
}

#endif //RPCLOGSYSTEM_INCLUDE_LOG_BUFFER_H