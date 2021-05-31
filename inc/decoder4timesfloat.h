#ifndef PCARS_DECODER_4TIMESFLOAT_H_
#define PCARS_DECODER_4TIMESFLOAT_H_

#include "../inc/decodercomposite.h"

#include "../inc/decoderf32.h"

namespace pcars {

	/// \class Decoder4TimesFloat
	/// \brief Decode Float 4 times

	class Decoder4TimesFloat : public DecoderComposite {
	public:
		/// Constructor
		Decoder4TimesFloat();
		/// Destructor
		virtual ~Decoder4TimesFloat() {}

		/// \brief Get vector of floats
		///
		///
		/// \return value
		/// \throw nothing

		Vector_Float times4_float() const;

	private:
		DecoderF32 first_;
		DecoderF32 second_;
		DecoderF32 third_;
		DecoderF32 forth_;
	};

}

#endif

