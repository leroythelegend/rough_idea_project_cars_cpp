#ifndef PCARS_PACKET_CLASS_INFO_H_
#define PCARS_PACKET_CLASS_INFO_H_

#include "../inc/decodercomposite.h"

#include "../inc/consts.h"

#include "../inc/decoderu32.h"
#include "../inc/decoderu16.h"
#include "../inc/decoder20char.h"

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

