#include "packetgeneric.h"

namespace pcars {

PacketGeneric::PacketGeneric() {
	add(&buildversion_);
	add(&sequencenum_packettype_);
}

PacketGeneric::~PacketGeneric() {
}


uint16_t PacketGeneric::build_version() const {
	return buildversion_.u16();
}

unsigned int PacketGeneric::sequence_number() const {
	return sequencenum_packettype_.ms6bits();
}

Packet_Type PacketGeneric::packet_type() const{
	return static_cast<Packet_Type>(sequencenum_packettype_.ls2bits());
}

}

