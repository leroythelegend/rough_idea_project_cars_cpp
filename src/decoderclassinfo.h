#ifndef PCARS_PACKET_CLASS_INFO_H_
#define PCARS_PACKET_CLASS_INFO_H_

#include "decodercomposite.h"

#include "consts.h"

#include "decoderu32.h"
#include "decoderu16.h"
#include "decoder20char.h"

namespace pcars {

	/// \class DecoderClassInfo
	/// \brief Decodes Class info

	class DecoderClassInfo : public DecoderComposite {
	public:

		/// Constructor
		DecoderClassInfo();
		/// Destructor
		virtual ~DecoderClassInfo() {}

		/// \brief Get class index
        ///
        ///
        /// \return value
        /// \throw nothing

		unsigned int class_index() const;

		/// \brief Get name
        ///
        ///
        /// \return value
        /// \throw nothing

		std::string name() const;

	private:
		DecoderU32 classindex_;
		Decoder20Char name_;
	};

}

#endif

