// tcp_communication.h
#ifndef TCP_COMMUNICATION_H
#define TCP_COMMUNICATION_H

#include "packet.h"

class TCPCommunication {
public:
    TCPCommunication();
    ~TCPCommunication();

    bool connect(const char* server_ip, int port);
    bool sendPacket(const Packet& packet);
    bool receivePacket(Packet& packet);

private:
    int sockfd;
};

#endif
