#ifndef PCARS_DECODER_16TIMES_64CHAR_H_
#define PCARS_DECODER_16TIMES_64CHAR_H_

#include "../inc/decodercomposite.h"

#include "../inc/decoder64char.h"

namespace pcars {

	/// \class Decoder16Times64Char
	/// \brief Decode 64 chars into vector

	class Decoder16Times64Char : public DecoderComposite {
	public:
		/// Constructor
		Decoder16Times64Char();
		/// Destructor
		virtual ~Decoder16Times64Char() {}

		/// \brief Get vector of strings
		///
		///
		/// \return value
		/// \throw nothing

		Vector_String times16_64Char() const;

	private:
		Decoder64Char first_;
		Decoder64Char second_;
		Decoder64Char third_;
		Decoder64Char forth_;
		Decoder64Char fith_;
		Decoder64Char sixth_;
		Decoder64Char seventh_;
		Decoder64Char eightth_;
		Decoder64Char nineth_;
		Decoder64Char tenth_;
		Decoder64Char eleventh_;
		Decoder64Char twelve_;
		Decoder64Char thirteen_;
		Decoder64Char forteen_;
		Decoder64Char fithteen_;
		Decoder64Char sixteen_;
	};

}

#endif

