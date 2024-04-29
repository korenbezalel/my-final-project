#ifndef PACKET_H
#define PACKET_H

#include <cstdint>

//defining the packet header 
struct PacketHeader   
{
    uint8_t version_ihl;     // Version (4 bits) + Internet Header Length (4 bits)
    uint8_t dscp_ecn;        // Differentiated Services Code Point (6 bits) + Explicit Congestion Notification (2 bits)
    uint16_t total_length;   // Total Length
    uint16_t identification; // Identification
    uint16_t flags_frag_off; // Flags (3 bits) + Fragment Offset (13 bits)
    uint8_t ttl;             // Time to Live
    uint8_t protocol;        // Protocol (TCP = 6)
    uint16_t header_checksum;// Header Checksum
    uint32_t src_ip;         // Source IP Address
    uint32_t dest_ip;        // Destination IP Address
};

struct Packet
{
    PacketHeader header;     // existing PacketHeader struct
    //tieing up the header part and the data part of the packet
    uint16_t src_port;       // Source Port
    uint16_t dest_port;      // Destination Port
    uint32_t sequence_num;   // Sequence Number
    uint32_t ack_num;        // Acknowledgment Number
    uint8_t data_offset;     // Data Offset (4 bits) + Reserved (4 bits)
    uint8_t flags;           // Flags (e.g., SYN, ACK, FIN)
    uint16_t window_size;    // Window Size
    uint16_t checksum;       // Checksum
    uint16_t urgent_ptr;     // Urgent Pointer
    char data[1024];         // Data (up to 1024 bytes)
};

#endif
