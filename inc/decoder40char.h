#ifndef PCARS_DECODER_40CHAR_H_
#define PCARS_DECODER_40CHAR_H_

#include "../inc/decoder.h"

#include <string>

namespace pcars {

	/// \class Decoder40Char
	class Decoder40Char : public Decoder {
	public:
		/// Constructor
		Decoder40Char();
		/// Destructor
		virtual ~Decoder40Char() {}

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

		std::string char40() const;

	private:
		std::string char40_;
	};

}

#endif

