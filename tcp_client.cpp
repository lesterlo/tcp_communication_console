#include "tcp_client.h"

TCP_Client::TCP_Client(std::string server_ip, std::string server_port):_server_ip(server_ip), _server_port(server_port), _send_counter(0)
{

}

TCP_Client::~TCP_Client()
{
    close(_connection_sd);
}

void TCP_Client::open_conn()
{
    //Reusable Socket
	_connection_sd = socket(AF_INET, SOCK_STREAM, 0);
	long val = 1;
	if (setsockopt(_connection_sd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(long)) == -1) {
		std::cerr << "setsockoptstd::" << std::endl;
		exit(1);
	}
	//Connect
	struct sockaddr_in server_addr;
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(_server_ip.c_str());
	server_addr.sin_port = htons(atoi(_server_port.c_str()));
	if (connect(_connection_sd,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
		std::cerr << "connection error " << std::endl;
        return;
	}
}

void TCP_Client::run_job()
{
    while(true)
    {
        int send_length = 0;
        std::stringstream msg;
        msg << "ClientSend_" << _send_counter;
        send_length = send(_connection_sd, msg.str().c_str(), msg.str().length(), 0);

        _send_counter++;

        //Recieved the server's echo
        int recv_length = 0;
		if((recv_length =recv(_connection_sd, _data_buffer, BUFSIZE, 0)) == -1)
        { //Read in a request
			std::cout << "[Error]: " << "Unable to read request" << std::endl;

            break;
		} 
        else if(recv_length>0)
        {
            std::cout << "Received: ";
            for(int i=0; i< recv_length; i++)
                std::cout << _data_buffer[i];
            std::cout << std::endl;
        }


        std::this_thread::sleep_for(std::chrono::seconds(MSG_INTERVAL)); 
    }
}