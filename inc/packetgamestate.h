#ifndef PCARS_PACKET_GAME_STATE_H_
#define PCARS_PACKET_GAME_STATE_H_

#include "../inc/packet.h"

#include "../inc/packetbase.h"

#include "../inc/decoderu16.h"
#include "../inc/decoder3bit3bit.h"
#include "../inc/decoders8.h"
#include "../inc/decoderu8.h"

namespace pcars {

	/// \class PacketGameState
	/// \brief Packet Game State

	class PacketGameState : public Packet {
	public:
		/// Constructor
		PacketGameState();
		/// Destructor
		virtual ~PacketGameState() {}

		/// \brief Get packet base
		///
		/// \return Packet base
		/// \throw nothing

		PacketBase packet_base() const;

		/// \brief Get build version
		///
		/// \return Build version
		/// \throw nothing

		unsigned int build_version() const;

		/// \brief Get game state
		///
		/// \return Game state
		/// \throw nothing

		unsigned int game_state() const;
		
		/// \brief Get session state
		///
		/// \return Session state
		/// \throw nothing

		unsigned int sessin_state() const;

		/// \brief Get ambient temperature
		///
		/// \return Ambient temp
		/// \throw nothing

		int ambient_temperature() const;

		/// \brief Get track temp
		///
		/// \return Track temp
		/// \throw nothing

		int track_temperature() const;

		/// \brief Get rain density
		///
		/// \return Rain Density
		/// \throw nothing

		unsigned int rain_density() const;

		/// \brief Get snow density
		///
		/// \return Snow density
		/// \throw nothing

		unsigned int snow_density() const;


		/// \brief Get wind speed
		///
		/// \return Wind speed
		/// \throw nothing

		int wind_speed() const;

		/// \brief Get wind direction x
		///
		/// \return Wind direction x
		/// \throw nothing

		int wind_direction_x() const;

		/// \brief Get wind direction y
		///
		/// \return Wind direction y
		/// \throw nothing

		int wind_direction_y() const;

        /// \brief Get packet format
        ///
        ///     format 2
        ///
        /// \return Format
        /// \throw nothing

		Format format() const override { return 2; }

		/// \brief Get packet type
        ///
        ///
        /// \return Packet type
        /// \throw nothing

		Type type() const override { return PACKETTYPE::PACKETGAMESTATE;}

	private:
		PacketBase packet_base_;
		DecoderU16 build_version_;
		Decoder3bit3bit game_session_state_;
		DecoderS8 ambient_temperature_;
		DecoderS8 track_temperature_;
		DecoderU8 rain_density_;
		DecoderU8 snow_density_;
		DecoderS8 wind_speed_;
		DecoderS8 wind_direction_x_;
		DecoderS8 wind_direction_y_;
	};

}

#endif

