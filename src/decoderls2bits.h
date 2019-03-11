#ifndef PCARS_DECODER_LS2BITS_H_
#define PCARS_DECODER_LS2BITS_H_

#include "decoder.h"

namespace pcars {

	/// \class DecoderLS2bits 
	/// \brief Decode LS 2 bits from byte

	class DecoderLS2bits : public Decoder {
	public:
		/// Constructor
		DecoderLS2bits();
		/// Destructor
		virtual ~DecoderLS2bits();

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get value of LS 2 bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int ls2bits() const;

	private:
		int num_;
	};

}

#endif

