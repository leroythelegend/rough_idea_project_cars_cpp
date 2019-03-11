#ifndef PCARS_DECODER_4TIMES_U16_H_
#define PCARS_DECODER_4TIMES_U16_H_

#include "decodercomposite.h"

#include "decoderu16.h"

namespace pcars {

	/// \class Decoder4TimesU16
	class Decoder4TimesU16 : public DecoderComposite {
	public:
		/// Constructor
		Decoder4TimesU16();
		/// Destrutor
		virtual ~Decoder4TimesU16() {}

		/// \brief Get vector of unsigned int
		///
		///
		/// \return value
		/// \throw nothing

		Vector_UInt times4_u16() const;

	private:
		DecoderU16 first_;
		DecoderU16 second_;
		DecoderU16 third_;
		DecoderU16 forth_;
	};

}

#endif

