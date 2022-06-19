#ifndef TEST_SERVER_H
#define TEST_SERVER_H
#pragma once

#include <io.h>
#include <iostream>
#include <ostream>

#include "SimpleServer.h"

using namespace ServerCpp;

namespace ServerCpp
{
    class TestServer : public SimpleServer
    {
    public:
        TestServer(int domain, int service, int protocol, int port, u_long address, int backlog);
        void Run() override;
    private:
        char _buffer[3000] = { 0 };
        int _newSocket{};
        
        void Accepter() override;
        void Handler() override;
        void Responder() override;
    };
}

#endif
