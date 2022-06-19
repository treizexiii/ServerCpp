#pragma comment(lib, "ws2_32.lib")
#include <stdio.h>
#include "Networking/Servers/TestServer.h"

using namespace ServerCpp;

int main(int argc, char* argv[])
{
    auto server = TestServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10);
    server.Run();
    
    return 0;
}
