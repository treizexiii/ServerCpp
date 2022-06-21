#ifndef CONNECTING_SOCKET_H
#define CONNECTING_SOCKET_H
#pragma once
#include "SimpleSocket.h"

namespace ServerCpp
{
    class ConnectingSocket : public SimpleSocket
    {
        int _connection;
    public:
        ConnectingSocket(int domain,
                      int service, int protocol, int port, u_long link);
        int ConnectToNetwork(SOCKET sock, sockaddr_in address) override;
    };
}

#endif
