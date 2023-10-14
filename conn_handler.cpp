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
        std::cout << "hello thread: "<< _client_sd << std::endl;
    }

}
