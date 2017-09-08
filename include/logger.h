/**
*
* @file	    logger.h
* @author	SHIBO
* @date		2017/7/7
* @version 	1.1
* @brief	系统日志类
*           
*/

#ifndef RPCLOGSYSTEM_INCLUDE_LOGGER_H
#define RPCLOGSYSTEM_INCLUDE_LOGGER_H
#include <stdio.h>
#include <mutex>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdio> //needed for printf

//trace日志宏定义
#define LOG_TRACE(x) _logger->trace(__FILE__, __func__, __LINE__, x)
//error日志宏定义
#define LOG_DEBUG(x) _logger->debug(__FILE__, __func__, __LINE__, x)
//debug日志宏定义
#define LOG_ERROR(x) _logger->error(__FILE__, __func__, __LINE__, x)
//debug日志宏定义
#define LOG_FATAL(x) _logger->fatal(__FILE__, __func__, __LINE__, x)

namespace system_log
{

class Logger
{
public:
    //获取Logger单例
    static Logger *getLogger();
    
    ~Logger();
    
    /* 
                  @description 设置日志输出级别
                  @param level 日志输出级别
                  */
    
    
    int set_level(int level);
    
    /* 
                  @description 输出fatal日志
                  @param log 文件名
                  @param log 函数名
                  @param log 行号
                  @param log 日志消息
                  */
    int fatal(std::string file, std::string func, int line, std::string log);
    
    /* 
                  @description 输出error日志
                   @param log 文件名
                  @param log 函数名
                  @param log 行号
                  @param log 日志消息
                  */
    int error(std::string file, std::string func, int line, std::string log);
    
    /* 
                  @description 输出warn日志
                   @param log 文件名
                  @param log 函数名
                  @param log 行号
                  @param log 日志消息
                  */
    int warn(std::string file, std::string func, int line, std::string log);
    
    /* 
                  @description 输出info日志
                   @param log 文件名
                  @param log 函数名
                  @param log 行号
                  @param log 日志消息
                  */
    int info(std::string file, std::string func, int line, std::string log);
    
    /* 
                  @description 输出debug日志
                   @param log 文件名
                  @param log 函数名
                  @param log 行号
                  @param log 日志消息
                  */
    int debug(std::string file, std::string func, int line, std::string log);
    
    /* 
                  @description 输出trace日志
                   @param log 文件名
                  @param log 函数名
                  @param log 行号
                  @param log 日志消息
                  */
    int trace(std::string file, std::string func, int line, std::string log);
    
    private:
        //日志输出级别
        static int _level;
        //日志操作对象（单例）
        static Logger *_logger;
        //构造函数
        Logger();
    
        /* 
                  @description 输出日志
                  @param level 待输出日志的级别
                   @param log 文件名
                  @param log 函数名
                  @param log 行号
                  @param log 日志消息
                  */
        int print_log(int level, std::string file, std::string func, int line, std::string log);
};
}

#endif //RPCLOGSYSTEM_INCLUDE_LOGGER_H