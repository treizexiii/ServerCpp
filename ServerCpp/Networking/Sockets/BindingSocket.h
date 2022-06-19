#ifndef bindingSocket_h
#define BINDING_SOCKET_H

#pragma once

#include "SimpleSocket.h"

namespace ServerCpp
{
    class BindingSocket : public SimpleSocket
    {
        int _binding;
    public:
        // Constructor
        BindingSocket(int domain,
                      int service, int protocol, int port, u_long link);
        // Definition of ConnectToNetwork virtual function
        int ConnectToNetwork(int sock, sockaddr_in address) override;
        int GetBinding();
    };
}

#endif
