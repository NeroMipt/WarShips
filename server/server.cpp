#include "server.hpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define BUFF_SIZE 1024
#define DEFAULT_PORT 1601



class Socket
{
private:
    struct sockaddr_in server_adress;
    int client, server;
    socklen_t size;

public:
    Socket(int port)
    {
        //initializing socket
        client = socket(AF_INET, SOCK_STREAM, 0);
        if (client < 0)
        {
            std::cout << "SERVER_ERROR: establishing socket error.\n";
            exit(0);
        }
        std::cout << "SERVER: Socket for server was successfully created\n";

        server_adress.sin_port = htons(port); // identifying port with macros
        server_adress.sin_family = AF_INET;
        server_adress.sin_addr.s_addr = htons(INADDR_ANY);
        size = sizeof(server_adress);

        int ret = bind(client, reinterpret_cast<struct sockaddr*>(&server_adress), size);

        if (ret < 0) {
            std::cout << EROFS << "binding connection. Socket has already been established. \n";
            exit(0);
        }

    }
    void start_listening()
    {
        std::cout << "SERVER: " << "Listening clients...";
        listen(client, 1);

        server = accept(client, reinterpret_cast<struct sockaddr*>(&server_adress), &size);
        if (server < 0)
        {
            std::cout << EROFS << "Can't accept clients.\n";
            exit(0);
        }

        char buffer[BUFF_SIZE];
        while(server > 0)
        {
            strcpy(buffer, "=> Server connected!\n");
            send(server, buffer, BUFF_SIZE, 0);
            std::cout << "=> Connected to client #1\n" << "Enter";
        }
    }
};


int main()
{
    Socket soc1(DEFAULT_PORT);

}
// int main(int argc, char const* argv[])
// {
//     int a = 1;
//     std::cout << a << "\n";
// }