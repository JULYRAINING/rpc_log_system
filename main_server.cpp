#include "include/server.h"

int main(){
    
    log_system_server::Server server("127.0.0.1", 1234);
    server.run();

}