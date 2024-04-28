#ifndef PACKET_BUILDER_H
#define PACKET_BUILDER_H

#include "packet.h"
#include "string"

class PacketBuilder {
public:
    PacketBuilder();
    ~PacketBuilder();

    Packet constructPacket(uint32_t sequence_number, const char* data, uint16_t data_length);

private:
    public static str::string 
};

#endif
