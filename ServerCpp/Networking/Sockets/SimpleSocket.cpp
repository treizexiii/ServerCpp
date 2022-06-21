#include "SimpleSocket.h"

#include <iostream>
#include <ostream>

ServerCpp::SimpleSocket::SimpleSocket(int domain,
                                      int service, int protocol, int port, u_long link)
{
    _address.sin_family = domain;
    _address.sin_port = htons(port);
    _address.sin_addr.S_un.S_addr = htonl(link);

    // Establish socket
    _socket = socket(domain, service, protocol);
    TestConnection(_socket);
}

void ServerCpp::SimpleSocket::TestConnection(int server)
{
    if (server < 0)
    {
        perror("Failed to connect...");
        std::cout << WSAGetLastError() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void ServerCpp::SimpleSocket::TestConnection(SOCKET server)
{
    if (server == NULL)
    {
        perror("Failed to connect...");
        exit(EXIT_FAILURE);
    }
}

sockaddr_in ServerCpp::SimpleSocket::GetAddress()
{
    return _address;
}

// int ServerCpp::SimpleSocket::GetSock()
// {
//     return _sock;
// }

SOCKET ServerCpp::SimpleSocket::GetSocket()
{
    return _socket;
}
