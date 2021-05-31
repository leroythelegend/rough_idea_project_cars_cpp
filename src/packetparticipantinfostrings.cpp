#include "../inc/packetparticipantinfostrings.h"

#include <string>

using namespace std;

namespace pcars {

PacketParticipantInfoStrings::PacketParticipantInfoStrings()
    : names_(16)
{
    add(&buildversion_);
    add(&sequencenum_packettype_);
    add(&carname_);
    add(&carclassname_);
    add(&tracklocation_);
    add(&trackvariation_);
    add(&names_);
    add(&fastest_lap_times_);
}

unsigned int PacketParticipantInfoStrings::build_version() const
{
    return buildversion_.u16();
}

unsigned int PacketParticipantInfoStrings::sequence_number() const
{
    return sequencenum_packettype_.ms6bits();
}

unsigned int PacketParticipantInfoStrings::packet_type() const
{
    return sequencenum_packettype_.ls2bits();
}

string PacketParticipantInfoStrings::car_name() const
{
    return carname_.char64();
}

string PacketParticipantInfoStrings::car_class_name() const
{
    return carclassname_.char64();
}

string PacketParticipantInfoStrings::track_location() const
{
    return tracklocation_.char64();
}

string PacketParticipantInfoStrings::track_variation() const
{
    return trackvariation_.char64();
}

Vector_String PacketParticipantInfoStrings::names() const
{
    return names_.string_vector();
}

Vector_Float PacketParticipantInfoStrings::fastest_lap_times() const
{
    return fastest_lap_times_.times16_float();
}

}