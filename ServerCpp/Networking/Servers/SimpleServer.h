#ifndef SIMPLE_SERVER_H
#define SIMPLE_SERVER_H
#pragma once

#include <stdio.h>
#include "../Sockets/ServerCpp-Sockets.h"

using namespace std;

namespace ServerCpp
{
    class SimpleServer
    {
    private:
        ListeningSocket* _mSocket;
        virtual void Accepter() = 0;
        virtual void Handler() = 0;
        virtual void Responder() = 0;
    public:
        SimpleServer(int domain, int service, int protocol, int port, u_long address, int backlog);
    protected:
        ~SimpleServer() = default;
    public:
        virtual void Run() = 0;
        ListeningSocket* GetSocket() const;
    };
}

#endif
