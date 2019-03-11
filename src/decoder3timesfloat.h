#ifndef PCARS_DECODER_3TIMES_FLOAT_H_
#define PCARS_DECODER_3TIMES_FLOAT_H_

#include "decodercomposite.h"

#include "decoderf32.h"

namespace pcars {

	/// \class Decoder3TimesFloat
	/// \brief Decode float 3 times

	class Decoder3TimesFloat : public DecoderComposite {
	public:
		/// Constructor
		Decoder3TimesFloat();
		/// Destructor
		virtual ~Decoder3TimesFloat() {}

		/// \brief Get vector of floats
		///
		///		Get vector size 3 of floats
		///
		/// \return value
		/// \throw nothing

		Vector_Float times3_float() const;

	private:
		DecoderF32 first_;
		DecoderF32 second_;
		DecoderF32 third_;
	};

}

#endif

