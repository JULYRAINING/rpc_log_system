#include "include/logger.h"

namespace system_log
{

Logger *Logger::_logger = 0;
int Logger::_level = 5;

Logger *Logger::getLogger()
{
    std::mutex mt;
    if (_logger == 0)
    {
        mt.lock();
        if (_logger == 0)
        {
            _logger = new Logger();
            
        }
        mt.unlock();
    }
    return _logger;
}

Logger::~Logger(){
    std::cout << "销毁Logger单例" << std::endl;
    delete _logger;
}

Logger::Logger()
{
     std::cout << "实例化Logger单例" << std::endl;
}
/* 
    @description 设置输出级别
    @param level 级别
    @return 0 设置成功
            -1 失败
*/
int Logger::set_level(int level)
{
    _level = level;
    std::cout << "设置日志输出级别" << std::endl;
}
/* 
    @description fatal级别日志
    @param log 日志信息
    @return 0 日志打印成功
            -1 失败
*/
int Logger::fatal(std::string file, std::string func, int line, std::string log)
{
    // return _logger->print_log(5, log);
    return _logger->print_log(5, file, func, line, log);
    // return 0;
}
/* 
    @description error
    @param log 日志信息
    @return 0 日志打印成功
            -1 失败
*/
int Logger::error(std::string file, std::string func, int line, std::string log)
{

    // return _logger->print_log(4, log);
    return _logger->print_log(4, file, func, line, log);
}
/* 
    @description warn级别日志
    @param log 日志信息
    @return 0 日志打印成功
            -1 失败
*/
int Logger::warn(std::string file, std::string func, int line, std::string log)
{
    // return _logger->print_log(3, log);
    return _logger->print_log(3, file, func, line, log);
}
/* 
    @description info级别日志
    @param log 日志信息
    @return 0 日志打印成功
            -1 失败
*/
int Logger::info(std::string file, std::string func, int line, std::string log)
{
    // return _logger->print_log(2, log);
    return _logger->print_log(2, file, func, line, log);
}
/* 
    @description debug级别日志
    @param log 日志信息
    @return 0 日志打印成功
            -1 失败
*/
int Logger::debug(std::string file, std::string func, int line, std::string log)
{
    // return _logger->print_log(1, log);
    return _logger->print_log(1, file, func, line, log);
}
/* 
    @description trace级别日志
    @param log 日志信息
    @return 0 日志打印成功
            -1 失败
*/
int Logger::trace(std::string file, std::string func, int line, std::string log)
{
    return _logger->print_log(0, file, func, line, log);
}
/* 
    @description level 日志输出级别
    @param log 日志信息
    @return 0 日志输出成功
            -1 失败
*/
int Logger::print_log(int level, std::string file, std::string func, int line, std::string log)
{

    // std::cout << "日志级别：" << level << std::endl;
    // std::cout << "日志输出级别：" << _level << std::endl;

    if (level >= _level)
    {
        std::cout << "[" << level << "]   ";
        //输出当前时间
        time_t t = time(0); // get time now
        struct tm *now = localtime(&t);
        std::cout << (now->tm_year + 1900) << '-'
                  << (now->tm_mon + 1) << '-'
                  << now->tm_mday << ' '
                  << now->tm_hour << ':'
                  << now->tm_min << ':'
                  << now->tm_sec
                  << "  ";

        std::cout << "file： " << file << ", method： " << func << ", line： " << line << ", detail: " << log << std::endl;

        return 0;
    }
    else
    {
        return -1;
    }
}
}