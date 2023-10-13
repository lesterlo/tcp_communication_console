#include "tcp_server.h"

TCP_Server::TCP_Server(int input_port): input_port_(port);
 
TCP_Server::~TCP_Server()
{
    close(socket_sd);
}

void TCP_Server::init_server()
{
	//Create TCP Socket
	if ((socket_sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		std::cerr << "[Fatal Error]: " << "cannot create socket\n" << std::endl; 
		exit (1);
	}
	//Set Reusable Port
	long val = 1;
	if(setsockopt(socket_sd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(long)) == -1){
		std::cerr << "[Fatal Error]: " << "Set Socket Reusable error" << std::endl;
	}

	//Bind the socket to any valid IP address and a specific port

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(input_port_);


	if (bind(socket_sd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		std::cerr << "[Fatal Error]: " << "bind failed" << std::endl;
		exit(1);
	}

	//Listen Port
	if(listen(socket_sd, handle_connection_num_) < 0){
		std::cerr << "[Fatal Error]: " << "Socket listen error" << std::endl;
		exit(1);
	}

}

void TCP_Server::run_server()
{
    while(1)
    {
        if((client_sd = accept(socket_sd, (struct sockaddr *) &client_addr, &client_addrlen)) < 0)
        {
			std::cerr << "[Fatal Error]: " << "Socket accpet failed" << std::endl;
			exit(0);
		}
        else 
        { //Connection accept
			std::cout << "[Info]: " << "Connection Accepted" << std::endl;
			
			// Client_thread_bundle *preAdd_bundle = new Client_thread_bundle;
			//preAdd_bundle->client_ptr = new Client_Reception(client_sd, client_addr, this);

			Client_Reception* ready_client = new Client_Reception(client_sd, client_addr, this);

			pthread_t pt_t;
			pthread_attr_t pt_attr;
			pthread_attr_init(&pt_attr);
			pthread_attr_setdetachstate(&pt_attr, PTHREAD_CREATE_DETACHED);

			pthread_create(&pt_t, &pt_attr, client_openning_deca,
					(void *) ready_client);

        }
    }
}
