#ifndef PCARS_DECODER_4TIMES_40CHAR_H_
#define PCARS_DECODER_4TIMES_40CHAR_H_

#include "decodercomposite.h"

#include "decoder40char.h"

namespace pcars {

	/// \class Decoder4Times40Char
	/// \brief Decode 40 chars 4 times

	class Decoder4Times40Char : public DecoderComposite {
	public:
		/// Constructor
		Decoder4Times40Char();
		/// Destructor
		virtual ~Decoder4Times40Char() {}

		/// \brief Get vector of strings
		///
		///
		/// \return value
		/// \throw nothing

		Vector_String times4_40Char() const;

	private:
		Decoder40Char first_;
		Decoder40Char second_;
		Decoder40Char third_;
		Decoder40Char forth_;
	};

}

#endif

