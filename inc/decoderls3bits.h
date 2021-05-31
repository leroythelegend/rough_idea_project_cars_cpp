#ifndef PCARS_DECODER_LS3BITS_H_
#define PCARS_DECODER_LS3BITS_H_

#include "../inc/decoder.h"

namespace pcars {

	/// \class DecoderLS3bits
	/// \brief Decode LS 3 bits from byte

	class DecoderLS3bits: public Decoder {
	public:
		/// Constructor
		DecoderLS3bits();
		/// Destructor
		virtual ~DecoderLS3bits();

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get value of LS 3 bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int ls3bits() const;

	private:
		unsigned int num_;
	};

}

#endif

