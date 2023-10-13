// C++ include
#include <iostream>
#include <vector>
#include <thread>
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

// #define DEBUG_MODE

#define BUFSIZE 2048
#define MAX_CONNECTION 10

typedef struct{
	std::string usr_name;
	std::string	usr_pw;
} Access_list_member;

// typedef struct{
// 	pthread_t client_thread;
// 	Client_Reception * client_ptr;
// } Client_thread_bundle;

class TCP_Server{
public:
	TCP_Server(int);
	~TCP_Server();
	void init_server();
	void run_server();
	bool compare_access();
	

private:
	int input_port_;
	int handle_connection_num_;

	struct sockaddr_in server_addr;      /* our address */
	struct sockaddr_in client_addr;     /* remote address */
	socklen_t client_addrlen;            /* length of addresses */
	int recvlen;                    /* # bytes received */
	int socket_sd;	//Server Socket descriptor
	int client_sd;	//Client Socket descriptor             
	unsigned char buf[BUFSIZE];     /* receive buffer */

	
	//Control
	bool running_flag;


};