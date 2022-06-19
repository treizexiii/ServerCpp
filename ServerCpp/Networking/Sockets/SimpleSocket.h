#ifndef SIMPLE_SOCKET_H
#define SIMPLE_SOCKET_H
#pragma comment(lib, "ws2_32.lib")
#pragma once
// #pragma comment(lib, "ws2_32.lib")


#include <winsock.h>

namespace ServerCpp
{
    class SimpleSocket
    {
    protected:
        ~SimpleSocket() = default;
    private:
        sockaddr_in _address{};
        int _sock;
    public:
        // Constructor
        SimpleSocket(int domain,
                     int service, int protocol, int port, u_long link);
        // Virtual function to connect to a network
        virtual int ConnectToNetwork(int sock, sockaddr_in address) = 0;
        // Function to test the connection
        void TestConnection(int server);
        sockaddr_in GetAddress();
        int GetSock();
    };
}

#endif
