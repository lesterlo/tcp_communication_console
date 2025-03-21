#pragma once



// C++ include
#include <iostream>
#include <vector>
#include <fstream>
//C include
#include <cstdio>
#include <cstdlib>
#include <cstring>
//Unix inlcude
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
//Self include
#include "conn_handler.h"
// #define DEBUG_MODE


#define MAX_CONNECTION 10


class TCP_Server{
public:
	TCP_Server(int);
	~TCP_Server();
	void conn_handle(int, struct sockaddr_in);
	void init_server();
	void run_server();

private:
	int input_port_;

	struct sockaddr_in server_addr;      /* our address */
	struct sockaddr_in client_addr;     /* remote address */
	socklen_t client_addrlen;            /* length of addresses */
	int _server_sd;	//Server Socket descriptor        
};