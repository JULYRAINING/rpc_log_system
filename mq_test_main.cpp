#include "include/mq.h"
#include "include/log.pb.h"
int main(){

    logsystem_messagequeue::MessageQueueTool* mq_tool1 = logsystem_messagequeue::MessageQueueTool::getInstance();

    rpc_log::Teacher teacher;
    rpc_log::Teacher teacher_empty;
    teacher.set_unique_name("rpc_log.Teacher");
    teacher.set_name("test");
    
    teacher.set_age(17);
   
    google::protobuf::Message* message = &teacher;
    int result;
    for (int i = 0; i < 100; i++){
        result = mq_tool1->push_msg(message);
        // EXPECT_EQ(0, result);
    }
}