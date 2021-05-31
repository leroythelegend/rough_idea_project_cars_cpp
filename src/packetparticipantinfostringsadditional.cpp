#include "../inc/packetparticipantinfostringsadditional.h"

namespace pcars {

PacketParticipantInfoStringsAdditional::PacketParticipantInfoStringsAdditional()
    : names_{16}
{
    add(&buildversion_);
    add(&sequencenum_packettype_);
    add(&offset_);
    add(&names_);
}

unsigned int PacketParticipantInfoStringsAdditional::build_version() const
{
    return buildversion_.u16();
}

unsigned int PacketParticipantInfoStringsAdditional::sequence_number() const
{
    return sequencenum_packettype_.ms6bits();
}

unsigned int PacketParticipantInfoStringsAdditional::packet_type() const
{
    return sequencenum_packettype_.ls2bits();
}

unsigned int PacketParticipantInfoStringsAdditional::offset() const
{
    return offset_.u8();
}

Vector_String PacketParticipantInfoStringsAdditional::names() const
{
    return names_.string_vector();
}

}
