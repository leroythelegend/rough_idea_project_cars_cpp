#include "../inc/packetbase.h"

namespace pcars {

PacketBase::PacketBase() {
	add(&packet_number_);
	add(&category_packet_number_);
	add(&partial_packet_index_);
	add(&partial_packet_number_);
	add(&packet_type_);
	add(&packet_version_);
}

unsigned int PacketBase::packet_number() const {
	return packet_number_.u32(); 
}

unsigned int PacketBase::category_packet_number() const {
	return category_packet_number_.u32(); 
}

unsigned int PacketBase::partial_packet_index() const {
	return partial_packet_index_.u8();
}

unsigned int PacketBase::partial_packet_number() const {
	return partial_packet_number_.u8();
}

unsigned int PacketBase::packet_type() const {
	return packet_type_.u8();
}

unsigned int PacketBase::packet_version() const {
	return packet_version_.u8();
}

}


