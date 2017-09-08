

#include "include/process.h"

namespace logsystem_process
{

Process::Process()
{
    _log_path = "/log";
    LOG_TRACE("初始化Process");
}
Process::~Process()
{
    LOG_DEBUG("销毁日志处理类");
}
Process::Process(std::string path)
{
    _log_path = path;
    LOG_TRACE("初始化Process");
}

/* 
@description 日志处理方法
@param message 日志消息
@return 0 处理成功
        1 处理失败

        对从消息队列中读取到的日志进行处理，将不同类型的message写入不同的文件中。
*/
int Process::process_msg(std::string message)
{

    

    int first = message.find_first_of("|");

    if(first == -1){
        for(int i = 0; i<1000; i++){
            LOG_ERROR("message~~~~~~~~~~~~~~~~~~~~~~~~~~ ： " + message + "");
        }
        
        return -1;
    }
    LOG_TRACE("first ： " + std::to_string(first) + "");

    std::string messagetype = message.substr(0, first);

    LOG_TRACE("messagetype ： " + messagetype + "");

    std::string data = message.substr(first + 1, message.length() - first);

    LOG_TRACE("data ： " + data + "");

    google::protobuf::Message *new_message = protobuf_tool.createMessage(messagetype.c_str());
    try{
        new_message->ParseFromString(data);
    }
    catch(...){
        LOG_ERROR("日志转化失败");
    }
    

    

    //Message字符串
    std::string message_string;
    //protobuf package.Message
    std::string unique_name;

    //将message信息转为string
    google::protobuf::TextFormat::Printer printer;
    printer.SetSingleLineMode(true);

    printer.PrintToString(*new_message, &message_string);
    //获取描述符
    const google::protobuf::Descriptor *descriptor = new_message->GetDescriptor();
    //获取字段描述符
    const google::protobuf::FieldDescriptor *field = descriptor->FindFieldByName("unique_name");
    printer.PrintFieldValueToString(*new_message, field, -1, &unique_name);
    LOG_TRACE("日志类型： " + unique_name);
    LOG_TRACE("日志内容： " + message_string);

    // 前后有引号，删除
    unique_name = unique_name.substr(1, unique_name.length() - 2);

    // 定义目录（细化目录）
    std::vector<std::string> file_paths = _buffer.split(unique_name, '.');

    std::string write_path = _log_path + "/" + file_paths[0];

    std::string _log_filename = file_paths[1] + ".log";

    LOG_DEBUG("日志存储路径： " + write_path + "/" + _log_filename);
    //写日志到文件
    //调用LogBuffer类将日志写入文件
    LOG_DEBUG("发送日志到缓冲区");
    _buffer.write(message_string, write_path, _log_filename);

  
    return 0;
    
}
}
