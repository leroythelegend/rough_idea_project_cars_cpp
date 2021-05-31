#ifndef PCARS_DECODER_16TIMES_U16_H_
#define PCARS_DECODER_16TIMES_U16_H_

#include "../inc/decodercomposite.h"

#include "../inc/decoderu16.h"

namespace pcars {

	/// \class Decoder16TimesU16
	/// \brief Decode unsigned short into vector

	class Decoder16TimesU16 : public DecoderComposite {
	public:
		/// Constructor
		Decoder16TimesU16();
		/// Destructor
		virtual ~Decoder16TimesU16() {}

		/// \brief Get vector of unsigned short
		///
		///
		/// \return value
		/// \throw nothing

		Vector_UInt times16_u16() const;

	private:
		DecoderU16 first_;
		DecoderU16 second_;
		DecoderU16 third_;
		DecoderU16 forth_;
		DecoderU16 fith_;
		DecoderU16 sixth_;
		DecoderU16 seventh_;
		DecoderU16 eightth_;
		DecoderU16 nineth_;
		DecoderU16 tenth_;
		DecoderU16 eleventh_;
		DecoderU16 twelve_;
		DecoderU16 thirteen_;
		DecoderU16 forteen_;
		DecoderU16 fithteen_;
		DecoderU16 sixteen_;

	};

}

#endif

