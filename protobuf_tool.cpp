
#include "include/protobuf_tool.h"

namespace log_system_server
{

ProtoBufferTool::ProtoBufferTool()
{
    LOG_TRACE("初始化ProtoBufferTool");
 }

ProtoBufferTool::~ProtoBufferTool()
{
    LOG_TRACE("初始化ProtoBufferTool");
 }

google::protobuf::Message *ProtoBufferTool::createMessage(const std::string &type_name)
{
    LOG_TRACE("根据message typt创建日志实体");
     google::protobuf::Message *message = NULL;
    const google::protobuf::Descriptor *descriptor =
        google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(type_name);
    if (descriptor)
    {
        const google::protobuf::Message *prototype =
            google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
        if (prototype)
        {
            message = prototype->New();
        }
    }
    LOG_TRACE("日志创建完成");
     return message;
}
}