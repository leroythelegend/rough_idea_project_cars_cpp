#include "../inc/packetparticipantsdata.h"

namespace pcars {

PacketParticipantsData::PacketParticipantsData() {
	add(&packet_base_);		
	add(&participants_changed_timestamp_);
	add(&name_);
	add(&nationality_);
	add(&index_);
}

PacketBase PacketParticipantsData::packet_base() const {
	return packet_base_;
}

unsigned int PacketParticipantsData::participants_changed_timestamp() const {
	return participants_changed_timestamp_.u32();
}

Vector_String PacketParticipantsData::name() const {
	return name_.times16_64Char();
}

Vector_UInt PacketParticipantsData::nationality() const {
	return nationality_.times16_u32();
}

Vector_UInt PacketParticipantsData::index() const {
	return index_.times16_u16();
}

}


