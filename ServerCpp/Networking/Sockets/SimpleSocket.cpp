#include "SimpleSocket.h"

ServerCpp::SimpleSocket::SimpleSocket(int domain,
    int service, int protocol, int port, u_long link)
{
    _address.sin_family = domain;
    _address.sin_port = htons(port);
    _address.sin_addr.S_un.S_addr = htonl(link);

    // Establish socket
    _sock = socket(domain, service, protocol);
    TestConnection(_sock);
}

void ServerCpp::SimpleSocket::TestConnection(int server)
{
    if (server < 0) {
        perror("Failed to connect...");
        exit(EXIT_FAILURE);
    }
}

sockaddr_in ServerCpp::SimpleSocket::GetAddress()
{
    return _address;
}

int ServerCpp::SimpleSocket::GetSock()
{
    return _sock;
}

