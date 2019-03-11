#include "decoderparticipantinfov1.h"

namespace pcars {

DecoderParticipantInfoV1::DecoderParticipantInfoV1() {
	add(&worldposition_);
	add(&currentlapdistance_);
	add(&raceposition_);
	add(&lapscompleted_);
	add(&currentlap_);
	add(&sector_);
	add(&lastsectortime_);

}

DecoderParticipantInfoV1::~DecoderParticipantInfoV1() {
}

Vector_Int DecoderParticipantInfoV1::world_position() const {
	return worldposition_.times3_s16();
}

unsigned int DecoderParticipantInfoV1::current_lap_distance() const {
	return currentlapdistance_.u16();
}

bool DecoderParticipantInfoV1::is_active() const {
	return raceposition_.msb_bool();
}

unsigned int DecoderParticipantInfoV1::race_position() const {
	return raceposition_.ls7_bits();
}

bool DecoderParticipantInfoV1::lap_invalidated() const {
	return lapscompleted_.msb_bool();
}

unsigned int DecoderParticipantInfoV1::laps_completed() const {
	return lapscompleted_.ls7_bits();
}

unsigned int DecoderParticipantInfoV1::current_lap() const {
	return static_cast<unsigned int>(currentlap_.u8());
}

bool DecoderParticipantInfoV1::same_class() const {
	return sector_.msb_1bit();
}

unsigned int DecoderParticipantInfoV1::world_positionZ() const {
	return sector_.top_2bit();
}

unsigned int DecoderParticipantInfoV1::world_positionX() const {
	return sector_.bottom_2bit();
}

unsigned int DecoderParticipantInfoV1::sector() const {
	return sector_.lsb_3bit();
}

float DecoderParticipantInfoV1::last_sector_time() const {
	return lastsectortime_.f32();
}




}

