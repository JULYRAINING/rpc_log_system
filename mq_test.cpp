#include "include/mq.h"
#include "include/log.pb.h"
#include <thread>
#include <gtest/gtest.h>

TEST(MessageQueueTool, GET_INSTANCE)
{

    logsystem_messagequeue::MessageQueueTool *mq_tool_test1 = logsystem_messagequeue::MessageQueueTool::getInstance();

    logsystem_messagequeue::MessageQueueTool *mq_tool_test2 = logsystem_messagequeue::MessageQueueTool::getInstance();
    EXPECT_TRUE(mq_tool_test1 != NULL);
    EXPECT_TRUE(mq_tool_test2 != NULL);
    EXPECT_TRUE(mq_tool_test1 == mq_tool_test2);
}

int consume(logsystem_messagequeue::MessageQueueTool *message_queue_tool)
{
    logsystem_process::ProcessInterface *process = new logsystem_process::Process();

    message_queue_tool->consume_msg(process);
    return 0;
}
int push(logsystem_messagequeue::MessageQueueTool *message_queue_tool)
{

    rpc_log::Teacher teacher;

    teacher.set_unique_name("unique_name");

    teacher.set_name("name");

    teacher.set_age(17);

    google::protobuf::Message *message = &teacher;

    while (true)
    {
        message_queue_tool->push_msg(message);
    }

    return 0;
}

TEST(MessageQueueTool, CONSUME)
{

    logsystem_messagequeue::MessageQueueTool *mq_tool_test1 = logsystem_messagequeue::MessageQueueTool::getInstance();

    logsystem_process::ProcessInterface *process = new logsystem_process::Process();
    // consume(process);
    std::thread push_thread(&push, mq_tool_test1);
    mq_tool_test1->consume_msg(process);
    // std::thread consume_thread(&consume, mq_tool_test1);
    
    // consume_thread.join();
    push_thread.join();
}
