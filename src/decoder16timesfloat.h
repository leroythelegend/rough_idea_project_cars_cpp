#ifndef PCARS_DECODER_16TIMES_FLOAT_H_
#define PCARS_DECODER_16TIMES_FLOAT_H_

#include "decodercomposite.h"

#include "decoderf32.h"

namespace pcars {

	/// \class Decoder3TimesFloat
	/// \brief Decode float 3 times

	class Decoder16TimesFloat : public DecoderComposite {
	public:
		/// Constructor
		Decoder16TimesFloat();
		/// Destructor
		virtual ~Decoder16TimesFloat() {}

		/// \brief Get vector of floats
		///
		///		Get vector size 16 of floats
		///
		/// \return value
		/// \throw nothing

		Vector_Float times16_float() const;

	private:
		DecoderF32 first_;
		DecoderF32 second_;
		DecoderF32 third_;
		DecoderF32 forth_;
		DecoderF32 fifth_;
		DecoderF32 sixth_;
		DecoderF32 seventh_;
		DecoderF32 eighth_;
		DecoderF32 ninth_;
		DecoderF32 tenth_;
		DecoderF32 eleventh_;
		DecoderF32 twelve_;
		DecoderF32 thirteen_;
		DecoderF32 forteen_;
		DecoderF32 fifteen_;
		DecoderF32 sixteen_;


	};

}

#endif

