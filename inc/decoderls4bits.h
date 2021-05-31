#ifndef PCARS_DECODER_LS4BITS_H_
#define PCARS_DECODER_LS4BITS_H_

#include "../inc/decoder.h"

namespace pcars {

	/// \class DecoderLS4bits
	/// \brief Decode LS 4 bits from byte

	class DecoderLS4bits : public Decoder {
	public:
		/// Constructor
		DecoderLS4bits();
		/// Destructor
		virtual ~DecoderLS4bits();

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get value of LS 4 bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int ls4bits() const;

	private:
		unsigned int num_;
	};

}

#endif

