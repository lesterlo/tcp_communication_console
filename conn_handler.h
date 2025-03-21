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

#define BUFSIZE 2048

#define ECHO_BACK_MSG_PREFIX "Server Echo:["
#define ECHO_BACK_MSG_SUFFIX "]"

class Conn_Handler
{
public:
    Conn_Handler(int, struct sockaddr_in );
    ~Conn_Handler();
    void run_handle();
private:
    int _client_sd;
    struct sockaddr_in _client_addr;
    unsigned char data_buffer[BUFSIZE];     /* receive buffer */
 
};