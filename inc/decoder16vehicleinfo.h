#ifndef PCARS_PACKET_16_VEHICLE_INFO_H_
#define PCARS_PACKET_16_VEHICLE_INFO_H_

#include "../inc/decodercomposite.h"

#include "../inc/decodervehicleinfo.h"

namespace pcars {

	/// \class Decoder16VehicleInfo
	/// \brief Decode 16 vehicle info

	class Decoder16VehicleInfo : public DecoderComposite {
	public:
		using Vector_Vehicle_Info = std::vector<DecoderVehicleInfo>;

		// Constructor
		Decoder16VehicleInfo();
		// Destructor
		virtual ~Decoder16VehicleInfo() {}

		/// \brief Get vector of Vehicle Info
		///
		///
		/// \return value
		/// \throw nothing

		Vector_Vehicle_Info vehicle_info() const;

	private:

		Vector_Vehicle_Info vehicle_info_;
	};

}

#endif

