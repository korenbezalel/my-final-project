#ifndef PACKET_BUILDER_H
#define PACKET_BUILDER_H
#include "string";
#include "packet.h";

class PacketBuilder
{
    public:
        PacketBuilder();
        ~PacketBuilder();
        //this will be diffind in the main script

        Packet constructPacket(uint32_t sequence_number, const char* data, uint16_t data_length);

        std::string CaesarCipherEncryption(const char* to_encrypt, int shift) 
        {
            std::string result = "";
            for (int i = 0; to_encrypt[i] != '\0'; ++i) {
                char encrypted_char = to_encrypt[i] + shift;
                if (std::islower(to_encrypt[i])) {
                    if (encrypted_char > 'z') {
                        encrypted_char = 'a' + (encrypted_char - 'z' - 1);
                    }
                }
                else if (std::isupper(to_encrypt[i])) {
                    if (encrypted_char > 'Z') {
                        encrypted_char = 'A' + (encrypted_char - 'Z' - 1);
                    }
                }
                result += encrypted_char;
            }
            return result;
        }

    

    private:

        //now there is no need to private functions' but I'll still keep it for a maybe futer use
    
};

#endif
