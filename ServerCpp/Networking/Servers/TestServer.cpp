#include "TestServer.h"

TestServer::TestServer(int domain, int service, int protocol, int port, u_long address, int backlog): SimpleServer(
    domain, service, protocol, port, address, backlog)
{
}

void TestServer::Run()
{
    while (true)
    {
        cout << "=== WAITING ===" << endl;
        Accepter();
        Handler();
        Responder();
        cout << "=== DONE ===" << endl;
    }
}

void TestServer::Accepter()
{
    auto address = GetSocket()->GetAddress();
    int addrlen = sizeof(address);
    typedef int socklen_t;
    _newSocket = accept(GetSocket()->GetSocket(), reinterpret_cast<sockaddr*>(&address),
                        reinterpret_cast<socklen_t*>(addrlen));
    _read(_newSocket, _buffer, 30000);
}

void TestServer::Handler()
{
    printf("On request");
    cout << _buffer << endl;
}

void TestServer::Responder()
{
    char hello[] = "Hello from server";
    _write(_newSocket, hello, strlen(hello));
    _close(_newSocket);
}
