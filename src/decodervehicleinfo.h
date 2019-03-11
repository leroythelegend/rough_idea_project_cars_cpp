#ifndef PCARS_PACKET_VEHICLE_INFO_H_
#define PCARS_PACKET_VEHICLE_INFO_H_

#include "decodercomposite.h"

#include "consts.h"

#include "decoderu32.h"
#include "decoderu16.h"
#include "decoder64char.h"

namespace pcars {

	/// \class DecoderVehicleInfo
	/// \brief Decodes Vehicle info

	class DecoderVehicleInfo : public DecoderComposite {
	public:

		/// Constructor
		DecoderVehicleInfo();
		/// Destructor
		virtual ~DecoderVehicleInfo() {}

		/// \brief Get index
        ///
        ///
        /// \return value
        /// \throw nothing

		unsigned int index() const;

		/// \brief Get class name
        ///
        ///
        /// \return value
        /// \throw nothing

		unsigned int class_name() const;

		/// \brief Get name
        ///
        ///
        /// \return value
        /// \throw nothing

		std::string name() const;

	private:
		DecoderU16 index_;
		DecoderU32 class_;
		Decoder64Char name_;
	};

}

#endif

