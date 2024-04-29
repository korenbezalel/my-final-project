// packet_builder.cpp
//this code its responsibale for briging the 2 .h files and constracting the final TCP packet
//also the code will be exported using dll to the .py code file of the server
#include "packet_builder.h"
#include <cstring>
#include <string>

PacketBuilder::PacketBuilder()
{
    // Constructor
}

PacketBuilder::~PacketBuilder()
{
    // Destructor
}

Packet PacketBuilder::constructPacket(uint32_t sequence_number, const char* data, uint16_t data_length, int shift)
{
    Packet packet;
    packet.header.sequence_number = sequence_number;
    packet.header.length = data_length;

    // Encrypting the data
    std::string encrypted_data = PacketBuilder::CaesarCipherEncryption(data,shift)

    // Copy the encrypted data into the packet
    std::memcpy(packet.data, encrypted_data.c_str(), encrypted_data.length());

    return packet;
}

