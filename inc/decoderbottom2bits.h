#ifndef PCARS_DECODER_BOTTOM_2BIT_H_
#define PCARS_DECODER_BOTTOM_2BIT_H_

#include "../inc/decoder.h"

namespace pcars {

	/// \class DecoderBottom2bits
	/// \brief Decode bottom 2 bits from byte

	class DecoderBottom2bits : public Decoder {
	public:
		/// Constructor
		DecoderBottom2bits();
		/// Destructor
		virtual ~DecoderBottom2bits() {}

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get value of botom 2 bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int bottom_2bit() const;

	private:
		unsigned int num_;
	};

}

#endif

