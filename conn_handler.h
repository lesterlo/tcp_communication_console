#pragma once 

//C++ header
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


//Linux header
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>

void pthread_opening_helper(void*);
void pthread_closeing_helper(void*);

class Conn_Handler
{
public:
    Conn_Handler(int, struct sockaddr_in );
    ~Conn_Handler();
    void run_handle();
private:
    int _client_sd;
    struct sockaddr_in _client_addr;
};