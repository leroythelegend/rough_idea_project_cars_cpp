#ifndef PCARS_DECODER_TELEMETRY_DATA_H_
#define PCARS_DECODER_TELEMETRY_DATA_H_

#include "packet.h"

#include "decoderu16.h"
#include "decoder6bit2bit.h"
#include "decoder3bit3bit.h"
#include "decoders8.h"
#include "decoder3bit.h"
#include "decoderu8.h"
#include "decoderf32.h"
#include "decoder2bit3bit.h"
#include "decoder3timesfloat.h"
#include "decoders16.h"
#include "decoder4bit4bit.h"
#include "consts.h"
#include "decoder4timesu8.h"
#include "decoder4timesfloat.h"
#include "decoder4timess16.h"
#include "decoder4timesu16.h"
#include "decoderparticipantinfov1.h"
#include "decoder56participantinfo.h"
#include "decoder2timesu8.h"
#include "decoderu32.h"

namespace pcars {

	/// \class PacketTelemetryDataV1
	/// \brief Packet of Telemetry data format 1

	class PacketTelemetryDataV1 : public Packet {
	public:
		using Vector_Participant_Info = std::vector<DecoderParticipantInfoV1>;

		/// Constructor
		PacketTelemetryDataV1();
		/// Destructor
		virtual ~PacketTelemetryDataV1();

		/// \brief Build version
		///
		///		Current value is 1104 (03/11/19)
		///
		/// \return Version

		unsigned int build_version() const;

		/// \brief Sequence Number
		///
		///		Loops around 0-62
		///
		/// \return Sequence Number

		unsigned int sequence_number() const;

		/// \brief Packet Type
		///
		///		mTelemetryData.sPacketType=0
		///
		/// \return Version
		
		unsigned int packet_type() const;

		/// \brief Session State
		///
		///		enum
		///     {
		///     	SESSION_INVALID = 0,
		///     	SESSION_PRACTICE,
		///     	SESSION_TEST,
		///     	SESSION_QUALIFY,
		///     	SESSION_FORMATION_LAP,
		///     	SESSION_RACE,
		///     	SESSION_TIME_ATTACK,
		///     	//-------------
		///     	SESSION_MAX
		///     };
		///
		/// \return Session State

		unsigned int session_state() const;

		/// \brief Game State
		///
		///		enum
		///		{
		///			GAME_EXITED = 0,
		///			GAME_FRONT_END,
		///			GAME_INGAME_PLAYING,
		///			GAME_INGAME_PAUSED,
		///			//-------------
		///			GAME_MAX
		///		};
		///
		/// \return Game State

		unsigned int game_state() const;

		/// \brief Viewed Participant Index
		///
		/// 	Assuming this is the participant I might be 
		///		viewing in some context????
		///
		/// \return Game State		

		int viewed_participant_index() const;

		/// \brief Number of Participants
		///
		/// 	Number of Participants
		///
		/// \return Number of Participants	
		
		int num_participants() const;

		/// \brief Unfiltered Throttle
		///
		/// 	Not sure what the difference is
		///     between this and throttle?
		///     Value 0-255
		///
		/// \return Throttle

		float unfiltered_throttle() const;

		/// \brief Unfiltered Brake
		///
		/// 	Not sure what the difference is
		///     between this and brake?
		///     Value 0-255
		///
		/// \return brake

		float unfiltered_brake() const;

		/// \brief Unfiltered Steering
		///
		/// 	Not sure what the difference is
		///     between this and steering?
		///     Value -127-127
		///
		/// \return steering

		float unfiltered_steering() const;

		/// \brief Unfiltered Clutch
		///
		/// 	Not sure what the difference is
		///     between this and clutch?
		///     Value 0-255
		///
		/// \return clutch

		float unfiltered_clutch() const;

		/// \brief Race State Flags
		///
		///	    enum
		///		{
		///			RACESTATE_INVALID,
		///			RACESTATE_NOT_STARTED,
		///			RACESTATE_RACING,
		///			RACESTATE_FINISHED,
		///			RACESTATE_DISQUALIFIED,
		///			RACESTATE_RETIRED,
		///			RACESTATE_DNF,
		///			//-------------
		///			RACESTATE_MAX
		///		};
		///
		/// \return race state

		unsigned int race_state_flags() const;
		
		unsigned int laps_in_event() const;
		float best_lap_time() const;
		float last_lap_time() const;
		float current_time() const;
		float split_time_ahead() const;
		float split_time_behind() const;
		float split_time() const;
		float event_time_remaining() const;
		float personal_fastest_lap_time() const;
		float world_fastest_lap_time() const;
		float current_sector1_time() const;
		float current_sector2_time() const;
		float current_sector3_time() const;
		float fastest_sector1_time() const;
		float fastest_sector2_time() const;
		float fastest_sector3_time() const;
		float personal_fastest_sector1_time() const;
		float personal_fastest_sector2_time() const;
		float personal_fastest_sector3_time() const;
		float world_fastest_sector1_time() const;
		float world_fastest_sector2_time() const;
		float world_fastest_sector3_time() const;
		unsigned int joy_pad() const;
		Flag_Reason flag_reason() const;
		Flag_Colour flag_colour() const;
		unsigned int pit_mode() const;
		Pit_Schedule pit_schedule() const;
		float oil_temp_celsius() const;
		float oil_pressure_kpa() const;
		float water_temp_celsius() const;
		float water_pressure_kpa() const;
		float fuel_pressure_kpa() const;
		unsigned int car_flags() const;
		unsigned int fuel_capacity() const;
		unsigned int brake() const;
		unsigned int throttle() const;
		float clutch() const;
		int steering() const;
		float fuel_level() const;
		float speed() const;
		unsigned int rpm() const;
		unsigned int max_rpm() const;
		int num_gears() const;
		int gear() const;
		float boost_amount() const;
		int enforced_pit_stop_lap() const;
		unsigned int crash_state() const;
		float odometer_km() const;
		Vector_Float orientation() const;
		Vector_Float local_velocity() const;
		Vector_Float world_velocity() const;
		Vector_Float angular_velocity() const;
		Vector_Float local_acceleration() const;
		Vector_Float world_acceleration() const;
		Vector_Float extents_centre() const;
		Vector_UInt tyre_flags() const;
		Vector_UInt terrain() const;
		Vector_Float tyre_y() const;
		Vector_Float tyre_rps() const;
		Vector_Float tyre_slip_speed() const;
		Vector_UInt tyre_temp() const;
		Vector_UInt tyre_grip() const;
		Vector_Float tyre_height_above_ground() const;
		Vector_Float tyre_lateral_stiffness() const;
		Vector_UInt tyre_wear() const;
		Vector_UInt brake_damage() const;
		Vector_UInt suspension_damage() const;
		Vector_Int brake_temp_celsius() const;
		Vector_UInt tyre_tread_temp() const;
		Vector_UInt tyre_layer_temp() const;
		Vector_UInt tyre_carcass_temp() const;
		Vector_UInt tyre_rim_temp() const;
		Vector_UInt tyre_internal_air_temp() const;
		Vector_Float wheel_local_position_y() const;
		Vector_Float ride_height() const;
		Vector_Float suspension_travel() const;
		Vector_Float suspension_velocity() const;
		Vector_UInt air_pressure() const;
		float engine_speed() const;
		float engine_torque() const;
		float aero_damage() const;
		float engine_damage() const;
		float ambient_temperature() const;
		float track_temperature() const;
		float rain_density() const;
		float wind_speed() const;
		float wind_direction_x() const;
		float wind_direction_y() const;
		Vector_Participant_Info participant_info() const;
		unsigned int track_length() const;
		Vector_UInt wings() const;
		unsigned int dpad() const;

        /// \brief Get packet format
        ///
        ///     format 1
        ///
        /// \return Format
        /// \throw nothing

		Format format() const override { return 1; }

		/// \brief Get packet type
        ///
        ///
        /// \return Packet type
        /// \throw nothing
				
		Type type() const override { return "PacketTelemetryDataV1";}

	private:
		DecoderU16 buildversion_;
		Decoder6bit2bit sequencenum_packettype_;
		Decoder3bit3bit sessionstate_gamestate_;
		DecoderS8 viewedparticipantindex_;
		DecoderS8 numparticipants_;
		DecoderU8 unfilteredthrottle_;
		DecoderU8 unfilteredbrake_;
		DecoderS8 unfilteredsteering_;
		DecoderU8 unfilteredclutch_;
		Decoder3bit racestateflags_;
		DecoderU8 lapsinevent_;
		DecoderF32 bestlaptime_;
		DecoderF32 lastlaptime_;
		DecoderF32 currenttime_;
		DecoderF32 splittimeahead_;
		DecoderF32 splittimebehind_;
		DecoderF32 splittime_;
		DecoderF32 eventtimeremaining_;
		DecoderF32 personalfastestlaptime_;
		DecoderF32 worldfastestlaptime_;
		DecoderF32 currentsector1time_;
		DecoderF32 currentsector2time_;
		DecoderF32 currentsector3time_;
		DecoderF32 fastestsector1time_;
		DecoderF32 fastestsector2time_;
		DecoderF32 fastestsector3time_;
		DecoderF32 personalfastestsector1time_;
		DecoderF32 personalfastestsector2time_;
		DecoderF32 personalfastestsector3time_;
		DecoderF32 worldfastestsector1time_;
		DecoderF32 worldfastestsector2time_;
		DecoderF32 worldfastestsector3time_;
		DecoderU16 joypad_;
		Decoder2bit3bit highestflagreason_highestflagcolour_;
		Decoder2bit3bit pitschedule_pitmode_;
		DecoderS16 oiltempcelsius_;
		DecoderU16 oilpressurekpa_;
		DecoderS16 watertempcelsius_;
		DecoderU16 waterpressurekpa_;
		DecoderU16 fuelpressurekpa_;
		DecoderU8 carflags_;
		DecoderU8 fuelcapacity_;
		DecoderU8 brake_;
		DecoderU8 throttle_;
		DecoderU8 clutch_;
		DecoderS8 steering_;
		DecoderF32 fuellevel_;
		DecoderF32 speed_;
		DecoderU16 rpm_;
		DecoderU16 maxrpm_;
		Decoder4bit4bit gearnumgears_;
		DecoderU8 boostamount_;
		DecoderS8 enforcedpitstoplap_;
		Decoder3bit3bit crashstate_;
		DecoderF32 odometerkm_;
		Decoder3TimesFloat orientation_;
		Decoder3TimesFloat localvelocity_;
		Decoder3TimesFloat worldvelocity_;
		Decoder3TimesFloat angularvelocity_;
		Decoder3TimesFloat localacceleration_;
		Decoder3TimesFloat worldacceleration_;
		Decoder3TimesFloat extentscentre_;

		Decoder4TimesU8 tyreflags_;
		Decoder4TimesU8 terrain_;
		Decoder4TimesFloat tyrey_;
		Decoder4TimesFloat tyrerps_;
		Decoder4TimesFloat tyreslipspeed_;
		Decoder4TimesU8 tyretemp_;
		Decoder4TimesU8 tyregrip_;
		Decoder4TimesFloat tyreheightaboveground_;
		Decoder4TimesFloat tyrelateralstiffness_;
		Decoder4TimesU8 tyrewear_;
		Decoder4TimesU8 brakedamage_;
		Decoder4TimesU8 suspensiondamage_;
		Decoder4TimesS16 braketempcelsius_;
		Decoder4TimesU16 tyretreadtemp_;
		Decoder4TimesU16 tyrelayertemp_;
		Decoder4TimesU16 tyrecarcasstemp_;
		Decoder4TimesU16 tyrerimtemp_;
		Decoder4TimesU16 tyreinternalairtemp_;
		Decoder4TimesFloat wheellocalpositiony_;
		Decoder4TimesFloat rideheight_;
		Decoder4TimesFloat suspensiontravel_;
		Decoder4TimesFloat suspensionvelocity_;
		Decoder4TimesU16 airpressure_;

		DecoderF32 enginespeed_;
		DecoderF32 enginetorque_;

		DecoderU8 aerodamage_;
		DecoderU8 enginedamage_;

		DecoderS8 ambienttemperature_;
		DecoderS8 tracktemperature_;
		DecoderU8 raindensity_;
		DecoderS8 windspeed_;
		DecoderS8 winddirectionx_;
		DecoderS8 winddirectiony_;

		Decoder56ParticipantInfo paricipantinfo_;

		DecoderF32 tracklength_;

		Decoder2TimesU8 wings_;

		DecoderU8 dpad_;
	};

}

#endif
