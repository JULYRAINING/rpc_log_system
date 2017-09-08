#ifndef RPCLOGSYSTEM_MQC_H
#define RPCLOGSYSTEM_MQC_H

#include "include/mq.h"
#include <unistd.h>

namespace logsystem_messagequeue
{

MessageQueueTool *MessageQueueTool::_s_message_queue_tool = 0;

MessageQueueTool *MessageQueueTool::getInstance()
{

    std::mutex mt;
    if (_s_message_queue_tool == 0)
    {
        mt.lock();
        if (_s_message_queue_tool == 0)
        {
            _s_message_queue_tool = new MessageQueueTool();
            // LOG_TRACE("消息队列已创建（单例）");
        }
        mt.unlock();
    }
    return _s_message_queue_tool;
}

MessageQueueTool::MessageQueueTool()
{
    LOG_DEBUG("创建消息队列");
    init();
}
MessageQueueTool::~MessageQueueTool()
{
    LOG_DEBUG("销毁消息队列");
    delete _s_message_queue_tool;
}
int MessageQueueTool::enqueue(std::string message)
{
    LOG_TRACE("向消息队列插入一条日志");
    LOG_TRACE("消息队列大小: " + std::to_string(_myqueue.size()));
    _myqueue.push(message);

    return 0;
}
int MessageQueueTool::dequeue(logsystem_process::ProcessInterface *consumer)
{

    if (_myqueue.empty())
    {

        return -1;
    }
    
    std::string message = _myqueue.front();

    _myqueue.pop();
    
    //处理
    consumer->process_msg(message);
    LOG_TRACE("从消息队列读取了一条日志");
    return 0;
}
int MessageQueueTool::init()
{
    LOG_DEBUG("初始化消息队列");
}
int MessageQueueTool::consume_msg(logsystem_process::ProcessInterface *consumer)
{
    LOG_DEBUG("启动读取线程");
    std::thread consume_thread(&MessageQueueTool::consume_msg_local_thread, this, consumer);
    consume_thread.join();
    return 0;
}
int MessageQueueTool::consume_msg_local_thread(logsystem_process::ProcessInterface *consumer)
{
    unsigned int microseconds;
    microseconds = 1000000;
    LOG_DEBUG("开始读取消息");

    while (true)
    {

        int flag = dequeue(consumer);

        if (flag != 0)
        {
            LOG_DEBUG("消息队列为空, 等待1s");
            usleep(microseconds);
            continue;
        }
    }
}

int MessageQueueTool::push_msg(std::string message)
{
    LOG_TRACE("开始发送消息");
    
    int result = enqueue(message);
    
    return 0;
}
}

#endif //RPCLOGSYSTEM_MQC_H