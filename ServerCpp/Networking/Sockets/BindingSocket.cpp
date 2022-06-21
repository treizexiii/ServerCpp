#include "BindingSocket.h"

ServerCpp::BindingSocket::BindingSocket(int domain,
                      int service, int protocol, int port, u_long link) : SimpleSocket(
            domain, service, protocol, port, link)
{
    // Establish connection to the socket
    _binding = BindingSocket::ConnectToNetwork(GetSocket(), GetAddress());
    TestConnection(_binding);
}

int ServerCpp::BindingSocket::ConnectToNetwork(SOCKET sock, sockaddr_in address)
{
    return bind(sock, reinterpret_cast<sockaddr*>(&address), sizeof(address));
}

int ServerCpp::BindingSocket::GetBinding()
{
    return _binding;
}
