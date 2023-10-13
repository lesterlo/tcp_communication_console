#include "tcp_server.h"
#include<iostream>

#define LISTENING_PORT 8088

int main(int argc, char *argv[])
{
    std::cout << "Hi, I am the server!" << std::endl;

    TCP_Server* server = new TCP_Server(LISTENING_PORT);

    server->init_server();
    server->run_server();

    return 0;
}