#ifndef PCARS_DECODER_16TIMES_U32_H_
#define PCARS_DECODER_16TIMES_U32_H_

#include "decodercomposite.h"

#include "decoderu32.h"

namespace pcars {

	/// \class Decoder16TimesU32
	/// \brief Decode Unsigned int to vector

	class Decoder16TimesU32 : public DecoderComposite {
	public:
		/// Constructor
		Decoder16TimesU32();
		/// Destructor
		virtual ~Decoder16TimesU32() {}

		/// \brief Get vector of unsigned int
		///
		///
		/// \return value
		/// \throw nothing

		Vector_UInt times16_u32() const;

	private:
		DecoderU32 first_;
		DecoderU32 second_;
		DecoderU32 third_;
		DecoderU32 forth_;
		DecoderU32 fith_;
		DecoderU32 sixth_;
		DecoderU32 seventh_;
		DecoderU32 eightth_;
		DecoderU32 nineth_;
		DecoderU32 tenth_;
		DecoderU32 eleventh_;
		DecoderU32 twelve_;
		DecoderU32 thirteen_;
		DecoderU32 forteen_;
		DecoderU32 fithteen_;
		DecoderU32 sixteen_;
	};

}

#endif

