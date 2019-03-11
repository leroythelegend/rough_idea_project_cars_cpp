#ifndef PCARS_PACKET_TELEMETRY_DATA_H_
#define PCARS_PACKET_TELEMETRY_DATA_H_

#include "packet.h"

#include "packetbase.h"

#include "decoderu16.h"
#include "decoders16.h"
#include "decoder3bit3bit.h"
#include "decoders8.h"
#include "decoderu8.h"
#include "decoderf32.h"
#include "decoder4timesfloat.h"
#include "decoder3timesfloat.h"
#include "decoder4timesu8.h"
#include "decoder4timess16.h"
#include "decoder4timesu16.h"
#include "decoder4timeschar40.h"
#include "decoder3timess16.h"
#include "decoder2timesu8.h"
#include "decoder4bit4bit.h"


namespace pcars {

	/// \class PacketTelemetryData
	/// \brief Packet of telemetry data

	class PacketTelemetryData : public Packet {
	public:
		/// Constructor
		PacketTelemetryData();
		/// Destructor
		virtual ~PacketTelemetryData() {}

		/// \brief Get packet base
		///
		/// \return Packet base
		/// \throw nothing

		PacketBase packet_base() const;

		/// \brief Viewed Participant Index
		///
		/// 	Assuming this is the participant I might be 
		///		viewing in some context????
		///
		/// \return Game State	

		int viewed_participant_index() const;

		/// \brief Unfiltered Throttle
		///
		/// 	Not sure what the difference is
		///     between this and throttle?
		///     Value 0-255
		///
		/// \return Throttle

		unsigned int unfiltered_throttle() const;

		/// \brief Unfiltered Brake
		///
		/// 	Not sure what the difference is
		///     between this and brake?
		///     Value 0-255
		///
		/// \return brake

		unsigned int unfiltered_brake() const;

		/// \brief Unfiltered Steering
		///
		/// 	Not sure what the difference is
		///     between this and steering?
		///     Value -127-127
		///
		/// \return steering

		int unfiltered_steering() const;

		/// \brief Unfiltered Clutch
		///
		/// 	Not sure what the difference is
		///     between this and clutch?
		///     Value 0-255
		///
		/// \return clutch
		
		unsigned int unfiltered_clutch() const;
		unsigned int car_flags() const;	
		int oil_temp_celsius() const;
		unsigned int oil_pressure_kpa() const;
		int water_temp_celsius() const;
		unsigned int water_pressure_kpa() const;
		unsigned int fuel_pressure_kpa() const;
		unsigned int fuel_capacity() const;
		unsigned int brake() const;
		unsigned int throttle() const;
		unsigned int clutch() const;
		float fuel_level() const;
		float speed() const;
		unsigned int rpm() const;
		unsigned int max_rpm() const;
		int steering() const;
		unsigned int gears() const;
		unsigned int gear() const;
		unsigned int boost_amount() const;
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
		Vector_UInt tyre_temp() const;
		Vector_Float tyre_height_above_ground() const;
		Vector_UInt tyre_wear() const;
		Vector_UInt brake_damage() const;
		Vector_UInt suspension_damage() const;
		Vector_Int brake_temp_celsius() const;
		Vector_UInt tyre_tread_temp() const;
		Vector_UInt tyre_layer_temp() const;
		Vector_UInt tyre_carcass_temp() const;
		Vector_UInt tyre_rim_temp() const;
		Vector_UInt tyre_internal_air_temp() const;
		Vector_UInt tyre_temp_left() const;
		Vector_UInt tyre_temp_center() const;
		Vector_UInt tyre_temp_right() const;	
		Vector_Float wheel_local_position_y() const;
		Vector_Float ride_height() const;
		Vector_Float suspension_travel() const;
		Vector_Float suspension_velocity() const;
		Vector_UInt suspension_ride_height() const;
		Vector_UInt air_pressure() const;
		float engine_speed() const;
		float engine_torque() const;
		Vector_UInt wings() const;
		unsigned int handbrake() const;
		unsigned int aero_damage() const;
		unsigned int engine_damage() const;
		unsigned int joy_pad_0() const;
		unsigned int  d_pad() const;
		Vector_String tyre_compound() const;
		float turbo_boost_pressure() const;
		Vector_Float full_position() const;
		unsigned int brake_bias() const;
		unsigned int tick_count() const;


        /// \brief Get packet format
        ///
        ///     format 2
        ///
        /// \return Format
        /// \throw nothing

		Format format() const override { return 2; };

		/// \brief Get packet type
        ///
        ///
        /// \return Packet type
        /// \throw nothing
		
		Type type() const override { return "PacketTelemetryData";}

	private:
		PacketBase packet_base_;
		DecoderS8 viewed_participant_index_;
		DecoderU8 unfiltered_throttle_;
		DecoderU8 unfiltered_brake_;
		DecoderS8 unfiltered_steering_;
		DecoderU8 unfiltered_clutch_;
		DecoderU8 car_flags_;	
		DecoderS16 oil_temp_celsius_;
		DecoderU16 oil_pressure_kpa_;
		DecoderS16 water_temp_celsius_;
		DecoderU16 water_pressure_kpa_;
		DecoderU16 fuel_pressure_kpa_;
		DecoderU8 fuel_capacity_;
		DecoderU8 brake_;
		DecoderU8 throttle_;
		DecoderU8 clutch_;
		DecoderF32 fuel_level_;
		DecoderF32 speed_;
		DecoderU16 rpm_;
		DecoderU16 max_rpm_;
		DecoderS8 steering_;
		Decoder4bit4bit gear_num_gears_;
		DecoderU8 boost_amount_;
		DecoderU8 crash_state_;
		DecoderF32 odometer_km_;
		Decoder3TimesFloat orientation_;
		Decoder3TimesFloat local_velocity_;
		Decoder3TimesFloat world_velocity_;
		Decoder3TimesFloat angular_velocity_;
		Decoder3TimesFloat local_acceleration_;
		Decoder3TimesFloat world_acceleration_;
		Decoder3TimesFloat extents_centre_;
		Decoder4TimesU8 tyre_flags_;
		Decoder4TimesU8 terrain_;
		Decoder4TimesFloat tyre_y_;
		Decoder4TimesFloat tyre_rps_;
		Decoder4TimesU8 tyre_temp_;
		Decoder4TimesFloat tyre_height_above_ground_;
		Decoder4TimesU8 tyre_wear_;
		Decoder4TimesU8 brake_damage_;
		Decoder4TimesU8 suspension_damage_;
		Decoder4TimesS16 brake_temp_celsius_;
		Decoder4TimesU16 tyre_tread_temp_;
		Decoder4TimesU16 tyre_layer_temp_;
		Decoder4TimesU16 tyre_carcass_temp_;
		Decoder4TimesU16 tyre_rim_temp_;
		Decoder4TimesU16 tyre_internal_air_temp_;
		Decoder4TimesU16 tyre_temp_left_;
		Decoder4TimesU16 tyre_temp_center_;
		Decoder4TimesU16 tyre_temp_right_;	
		Decoder4TimesFloat wheel_local_position_y_;
		Decoder4TimesFloat ride_height_;
		Decoder4TimesFloat suspension_travel_;
		Decoder4TimesFloat suspension_velocity_;
		Decoder4TimesU16 suspension_ride_height_;
		Decoder4TimesU16 air_pressure_;
		DecoderF32 engine_speed_;
		DecoderF32 engine_torque_;
		Decoder2TimesU8 wings_;
		DecoderU8 handbrake_;
		DecoderU8 aero_damage_;
		DecoderU8 engine_damage_;
		DecoderU32 joy_pad_0_;
		DecoderU8  d_pad_;
		Decoder4Times40Char tyre_compound_;
		DecoderF32 turbo_boost_pressure_;
		Decoder3TimesFloat full_position_;
		DecoderU8 brake_bias_;
		DecoderU32 tick_count_;

	};

}

#endif

