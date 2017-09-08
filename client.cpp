
#include "client.h"

namespace log_system_client
{
int Client::_s_send_log_count = 0;
Client::Client(std::string ip, int port)
{

    LOG_TRACE("初始化Client");

    _ip = ip;
    _port = port;
    client.set_options(_ip, _port);
}


int Client::run()
{
    LOG_TRACE("系统已启动");

    std::thread polling_thread(&Client::polling, this);

    // polling_thread.detach();
    for (int i = 0; i<120; i++){
        std::thread send_thread(&Client::send, this);
        send_thread.detach();
    }
    
    polling_thread.join();
    // send_thread.detach();
}
int Client::send()
{
    LOG_TRACE("启动日志发送线程");

    client.connection();

    //定义休眠时间
    unsigned int microseconds;
    microseconds = 10000;
    //记录发送消息数量
    int count;
    count = 0;
    //构造日志消息
    std::string message_type_teacher;
    std::string message_type_student;
    message_type_teacher = "rpc_log.Teacher";
    rpc_log::Teacher teacher;
    teacher.set_unique_name(message_type_teacher);
    teacher.set_name("teacher");
    teacher.set_age(11);

    message_type_student = "rpc_log.Student";
    rpc_log::Student student;
    student.set_unique_name(message_type_student);
    student.set_name("student");
    student.set_age(11);

    std::string sendData;

    google::protobuf::Message *message = &teacher;
    while (true)
    {
        if (count % 2 == 0)
        {
            teacher.set_age(++_s_send_log_count);
            teacher.SerializeToString(&sendData);
            message = &teacher;
            client.writing(message, message_type_teacher);
            usleep(microseconds);
        }
        else
        {
            student.set_age(++_s_send_log_count);
            student.SerializeToString(&sendData);
            message = &student;
            client.writing(message, message_type_student);
            usleep(microseconds);
        }
        }
    client.disconnect();
}

int Client::polling()
{

    logsystem_buffer::LogBuffer log_buffer;
    std::string log_path = "/local_log";
    std::string log_filename = "local.log";

    std::vector<std::string> local_logs;

    LOG_TRACE("启动本地轮询线程");
    //定义休眠时间
    unsigned int microseconds;
    microseconds = 10000;
    //构造日志消息
    rpc_log::Student teacher;
    teacher.set_unique_name("rpc_log.Student");
    teacher.set_name("重发");
    teacher.set_age(11);

    std::string sendData;

    google::protobuf::Message *message = &teacher;
    while (true)
    {

        LOG_TRACE("轮询检测本地日志");

        local_logs = log_buffer.read(log_path, log_filename);
        int len = local_logs.size();
        if (len != 0)
        {
            for (int i = 0; i < len; i++)
            {
                // client.writing(message);

                client.writing_str(local_logs[i]);
            }
            LOG_TRACE("本地日志已发送");
        }
        else
        {
            LOG_TRACE("没有本地日志");
        }
        usleep(microseconds);
    }
}
}