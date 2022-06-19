#pragma once
#ifndef LISTENING_SOCKET_H
#define LISTENING_SOCKET_H
#include "BindingSocket.h"

namespace ServerCpp
{
#pragma once

    class ListeningSocket : public BindingSocket
    {
        int _backlog;
        int _listening;
    public:
        ListeningSocket(int domain,
            int service, int protocol, int port, u_long link, int backlog);
        ~ListeningSocket();
        void StartListening();
    };
}
#endif // LISTENING_SOCKET_H
