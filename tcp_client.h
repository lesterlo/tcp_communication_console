#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <dirent.h>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>

#define BUFSIZE 2048


class TCP_Client{
public:
	TCP_Client(std::string , std::string );
	~TCP_Client();
	void open_conn();
	void run_job();

private:
	std::string _server_ip;
    std::string _server_port;

	struct sockaddr_in _server_addr;      /* our address */
	struct sockaddr_in _client_addr;     /* remote address */
	socklen_t _client_addrlen;            /* length of addresses */
	int _connection_sd;	//Socket descriptor      
    int _send_counter;  
    unsigned char _data_buffer[BUFSIZE];     /* receive buffer */
};