#ifndef PCARS_PACKET_60_CLASS_INFO_H_
#define PCARS_PACKET_60_CLASS_INFO_H_

#include "decodercomposite.h"

#include "decoderclassinfo.h"

namespace pcars {

	/// \class Decoder16ClassInfo
	/// \brief Decode 60 class info

	class Decoder60ClassInfo : public DecoderComposite {
	public:
		using Vector_Class_Info = std::vector<DecoderClassInfo>;

		// Constructor
		Decoder60ClassInfo();
		// Destructor
		virtual ~Decoder60ClassInfo() {}

		/// \brief Get vector of class Info
		///
		///
		/// \return value
		/// \throw nothing

		Vector_Class_Info class_info() const;

	private:

		Vector_Class_Info class_info_;
	};

}

#endif

