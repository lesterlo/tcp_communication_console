#include "tcp_server.h"

TCP_Server::TCP_Server(int input_port): input_port_(input_port)
{

}
 
TCP_Server::~TCP_Server()
{
    close(_server_sd);
}

void client_closeing_helper(void* client_conn){
	//Find the object in the vector and delete
	std::cout << "[INFO]: " << "Closing Client thread" << std::endl;
	delete ((Conn_Handler *) client_conn);
}
void* client_openning_helper(void* client_conn){
	pthread_cleanup_push(client_closeing_helper, client_conn);

	std::cout << "[INFO]: " << "New Client thread" << std::endl;
	((Conn_Handler *) client_conn)->run_handle();

	pthread_cleanup_pop(1);	
}


void TCP_Server::init_server()
{
	//Create TCP Socket
	if ((_server_sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		std::cerr << "[Fatal Error]: " << "cannot create socket\n" << std::endl; 
		exit (1);
	}
	//Set Reusable Port
	long val = 1;
	if(setsockopt(_server_sd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(long)) == -1){
		std::cerr << "[Fatal Error]: " << "Set Socket Reusable error" << std::endl;
	}

	//Bind the socket to any valid IP address and a specific port

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(input_port_);


	if (bind(_server_sd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		std::cerr << "[Fatal Error]: " << "bind failed" << std::endl;
		exit(1);
	}

	//Listen Port
	if(listen(_server_sd, MAX_CONNECTION) < 0){
		std::cerr << "[Fatal Error]: " << "Socket listen error" << std::endl;
		exit(1);
	}

}

void TCP_Server::run_server()
{
    while(true)
    {
		int client_sd;
		struct sockaddr_in client_addr;
        if((client_sd = accept(_server_sd, (struct sockaddr *) &client_addr, &client_addrlen)) < 0)
        {
			std::cerr << "[Fatal Error]: " << "Socket accept failed" << std::endl;
			exit(0);
		}
        else 
        { //Connection accepted
			std::cout << "[Info]: " << "Connection Accepted" << std::endl;

            //Create thread to handle the client
			Conn_Handler* ready_client = new Conn_Handler(client_sd, client_addr);

			pthread_t pt_t;
			pthread_attr_t pt_attr;
			pthread_attr_init(&pt_attr);
			pthread_attr_setdetachstate(&pt_attr, PTHREAD_CREATE_DETACHED);

			pthread_create(&pt_t, &pt_attr, client_openning_helper,
					(void *) ready_client);

        }
    }
}
