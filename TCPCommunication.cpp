// tcp_communication.cpp
#include "tcp_communication.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

TCPCommunication::TCPCommunication() {
    // Constructor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // Handle error if sockfd < 0
}

TCPCommunication::~TCPCommunication() {
    // Destructor
    close(sockfd);
}

bool TCPCommunication::connect(const char* server_ip, int port)
{
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(port);
    return (::connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0);
}

bool TCPCommunication::sendPacket(const Packet& packet)
{
    return (::send(sockfd, reinterpret_cast<const char*>(&packet), sizeof(Packet), 0) >= 0);
}

bool TCPCommunication::receivePacket(Packet& packet) 
{
    return (recv(sockfd, reinterpret_cast<char*>(&packet), sizeof(Packet), 0) >= 0);
}

bool TCPCommunication::sendPacketToClient(const Packet& packet, const char* client_ip) 
{
    struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = inet_addr(client_ip);
    client_addr.sin_port = htons(port); // Assuming 'port' is a member variable of TCPCommunication

    char buffer[sizeof(Packet)];
    std::memcpy(buffer, &packet, sizeof(Packet));
    ssize_t sent_bytes = sendto(sockfd, buffer, sizeof(Packet), 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
    return (sent_bytes == sizeof(Packet));
}

