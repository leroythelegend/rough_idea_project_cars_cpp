#ifndef PCARS_DECODER_4TIMES_U8_H_
#define PCARS_DECODER_4TIMES_U8_H_

#include "decodercomposite.h"

#include "decoderu8.h"

namespace pcars {

	/// \class Decoder4TimesU8
	/// \brief Decode vector of unsigned ints

	class Decoder4TimesU8 : public DecoderComposite {
	public:
		/// Constructor
		Decoder4TimesU8();
		/// Destructor
		virtual ~Decoder4TimesU8() {}

		/// \brief Get vector of unsigned int
		///
		///
		/// \return value
		/// \throw nothing

		Vector_UInt times4_u8() const;

	private:
		DecoderU8 first_;
		DecoderU8 second_;
		DecoderU8 third_;
		DecoderU8 forth_;
	};

}

#endif

