#include "include/process.h"
#include "include/process.hlog.pb.h"
#include "gtest/gtest.h"





TEST(PROCESS, PROCESS){

    logsystem_process::Process process;
    google::protobuf::Message* new_message;


    rpc_log::Teacher* teacher;
    rpc_log::Teacher* teacher_empty;
    teacher->set_unique_name("rpc_log.Teacher");
    teacher->set_name("test");
    teacher->set_age(17);
    new_message = teacher;
    int flag = process.process_msg(new_message);

    EXPECT_EQ(0, flag);
    

}
