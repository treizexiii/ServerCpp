#include "SimpleServer.h"

ServerCpp::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long address, int backlog)
{
    _mSocket = new ListeningSocket(domain, service, protocol, port, address, backlog);
}

ServerCpp::ListeningSocket* ServerCpp::SimpleServer::GetSocket() const
{
    return _mSocket;
}
