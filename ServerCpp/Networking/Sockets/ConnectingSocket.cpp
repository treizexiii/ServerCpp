#include "ConnectingSocket.h"

ServerCpp::ConnectingSocket::ConnectingSocket(int domain,
                      int service, int protocol, int port, u_long link) : SimpleSocket(
            domain, service, protocol, port, link)
{
    // Establish connection to the socket
    _connection = ConnectingSocket::ConnectToNetwork(GetSock(), GetAddress()));
    TestConnection(_connection);
}

int ServerCpp::ConnectingSocket::ConnectToNetwork(int sock, sockaddr_in address)
{
    return connect(sock, reinterpret_cast<sockaddr*>(&address), sizeof(address));
}
