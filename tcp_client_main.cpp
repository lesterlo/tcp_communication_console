#include<iostream>


int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        std::cout << "Argument invalid" << std::endl;
        std::cout << "./tcp_client [IP] [PORT]" << std::endl;
        return -1;
    }

    std::cout << "Connecting to IP:"<< argv[1] << " ,Port: " << argv[2]<< std::endl;



    return 0;
}