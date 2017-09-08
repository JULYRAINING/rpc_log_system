
#include <unistd.h>
#include <iostream>
#include "include/client.h"



//启动客户端
int main(){
    
    std::string ip = "127.0.0.1";
    int port = 1234;
    log_system_client::Client client(ip, port);
    client.run();
    
}