/**
*
* @file		mq.h
* @author	SHIBO
* @date		2017/7/7
* @version 	1.1
* @brief	服务器端 消息队列类
*           
*/

#ifndef RPCLOGSYSTEM_MQ_H
#define RPCLOGSYSTEM_MQ_H

#include <stdio.h>
#include <unistd.h>
#include <queue>
#include <string.h>
#include <semaphore.h>
#include <thread>
#include <mutex>

#include "process_interface.h"
#include "process.h"
#include "log.pb.h"
#include "logger.h"

namespace logsystem_messagequeue
{

class MessageQueueTool
{
  public:

    //析构函数
    ~MessageQueueTool();

    //获取单例
    static MessageQueueTool *getInstance();
    
    /* 
                @description 从消息队列中读取消息
                @param consumer 消息处理类
                */
    int consume_msg(logsystem_process::ProcessInterface *consumer);

    /* 
                @description 向消息队列中插入消息
                @param message 日志消息
                */
    int push_msg(std::string message);



  private:
    std::mutex _lock;
    //系统日志操作类
    system_log::Logger* _logger;
    //消息队列内部queue
    std::queue<std::string> _myqueue;

    //单例实例
    static MessageQueueTool *_s_message_queue_tool;

    //构造函数
    MessageQueueTool();
    
    /* 
                @description 启动消费线程
                @param consumer 消息处理类
                */
    int consume_msg_local_thread(logsystem_process::ProcessInterface *consumer);
    
    int init();
    //
    /* 
                @description 内部queue入队
                @param message 日志消息
                */
    int enqueue(std::string message);
    
    /* 
                @description 内部queue出队并处理
                @param consumer 消息处理类
                */
    int dequeue(logsystem_process::ProcessInterface *consumer);
};
}

#endif //RPCLOGSYSTEM_MQ_H