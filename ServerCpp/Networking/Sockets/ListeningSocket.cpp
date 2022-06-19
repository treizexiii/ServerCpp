#include "ListeningSocket.h"

ServerCpp::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long link, int backlog) :
    BindingSocket(domain, service, protocol, port, link)
{
    _backlog = backlog;
    StartListening();
    TestConnection(_listening);
}

ServerCpp::ListeningSocket::~ListeningSocket()
= default;

void ServerCpp::ListeningSocket::StartListening()
{
    _listening = listen(GetSock(), _backlog);
}

