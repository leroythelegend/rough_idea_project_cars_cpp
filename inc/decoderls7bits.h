#ifndef PCARS_DECODER_LS7BITS_H_
#define PCARS_DECODER_LS7BITS_H_

#include "../inc/decoder.h"

namespace pcars {

	/// \class DecoderLS7bits
	/// \brief Decode LS 7 bits from byte

	class DecoderLS7bits : public Decoder {
	public:
		/// Constructor
		DecoderLS7bits();
		/// Destructor
		virtual ~DecoderLS7bits();

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get value of LS 7 bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int ls7bits() const;

	private:
		unsigned int num_;
	};

}

#endif

