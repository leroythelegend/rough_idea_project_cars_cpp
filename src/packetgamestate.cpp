#include "packetgamestate.h"

namespace pcars {

PacketGameState::PacketGameState() {
	add(&packet_base_);
	add(&build_version_);
	add(&game_session_state_);
	add(&ambient_temperature_);
	add(&track_temperature_);
	add(&rain_density_);
	add(&snow_density_);
	add(&wind_speed_);
	add(&wind_direction_x_);
	add(&wind_direction_y_);
}

PacketBase PacketGameState::packet_base() const {
	return packet_base_;
}

unsigned int PacketGameState::build_version() const {
	return build_version_.u16();
}

unsigned int PacketGameState::game_state() const {
	return game_session_state_.ls3bits();
}

unsigned int PacketGameState::sessin_state() const {
	return game_session_state_.ms3bits();
}

int PacketGameState::ambient_temperature() const {
	return ambient_temperature_.s8();
}

int PacketGameState::track_temperature() const {
	return track_temperature_.s8();
}

unsigned int PacketGameState::rain_density() const {
	return rain_density_.u8();
}

unsigned int PacketGameState::snow_density() const {
	return snow_density_.u8();
}

int PacketGameState::wind_speed() const {
	return wind_speed_.s8();
}

int PacketGameState::wind_direction_x() const {
	return wind_direction_x_.s8();
}

int PacketGameState::wind_direction_y() const {
	return wind_direction_y_.s8();
}

}

