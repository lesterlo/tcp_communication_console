#include "tcp_client.h"
#include <iostream>


int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        std::cout << "Argument invalid" << std::endl;
        std::cout << "./tcp_client [IP] [PORT]" << std::endl;
        return -1;
    }

    std::cout << "Connecting to IP:"<< argv[1] << " ,Port: " << argv[2]<< std::endl;

    TCP_Client* client = new TCP_Client(std::string(argv[1]), std::string(argv[2]));

    client->open_conn();
    client->run_job();

    return 0;
}