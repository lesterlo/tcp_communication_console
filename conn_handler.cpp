#include "conn_handler.h"

Conn_Handler::Conn_Handler(int client_sd, struct sockaddr_in client_addr):_client_sd(client_sd), _client_addr(client_addr)
{

}

Conn_Handler::~Conn_Handler()
{
    close(_client_sd);
}

void Conn_Handler::run_handle()
{
    while(true)
    {
        int recv_length = 0;
		if((recv_length =recv(_client_sd, data_buffer, BUFSIZE, 0)) == -1)
        { //Read in a request
			std::cout << "[Error]: " << "Unable to read request" << std::endl;

            break;
		} 
        else if(recv_length>0)
        {
            std::cout << "Received: ";
            for(int i=0; i< recv_length; i++)
                std::cout << data_buffer[i];
            std::cout << std::endl;

            //Echo back
            int send_length = 0;
            send_length = send(_client_sd, data_buffer, recv_length, 0);
        }
    }

}


