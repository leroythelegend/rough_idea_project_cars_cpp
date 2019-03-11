#ifndef PCARS_DECODER_64CHAR_H_
#define PCARS_DECODER_64CHAR_H_

#include "decoder.h"

#include <string>

namespace pcars {

	/// \class Decoder64Char
	/// \brief Decode 64 chars into vector of strings

	class Decoder64Char : public Decoder {
	public:
		/// Constructor
		Decoder64Char();
		/// Destructor
		virtual ~Decoder64Char() {}

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get vector of strings
		///
		///
		/// \return value
		/// \throw nothing

		std::string char64() const;

	private:
		std::string char64_;
	};

}

#endif

