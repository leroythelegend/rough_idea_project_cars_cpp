#ifndef PCARS_DECODER_20CHAR_H_
#define PCARS_DECODER_20CHAR_H_

#include "../inc/decoder.h"

#include <string>

namespace pcars {

	/// \class Decoder20Char
	/// \brief Decode 20 chars into vector of strings

	class Decoder20Char : public Decoder {
	public:
		/// Constructor
		Decoder20Char();
		/// Destructor
		virtual ~Decoder20Char() {}

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

		std::string char20() const;

	private:
		std::string char20_;
	};

}

#endif

