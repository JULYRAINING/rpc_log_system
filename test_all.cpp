
#include "gtest/gtest.h" 


#include "include/log_buffer.h" 
/*
#include "include/process.h" 
#include "include/mq.h" 
#include "include/log.pb.h" 
#include "include/client.h" 
#include "include/process_interface.h" 
#include "include/socket_tool_client.h" 
#include "include/socket_tool_server.h"
*/

int main(int argc, char **argv) 
{ 
testing::InitGoogleTest(&argc,argv); 
RUN_ALL_TESTS(); 
return 0; 
}
