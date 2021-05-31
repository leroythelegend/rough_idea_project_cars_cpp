#ifndef PCARS_DECODER_MS2BITS_H_
#define PCARS_DECODER_MS2BITS_H_

#include "../inc/decoder.h"

namespace pcars {

	/// \class DecoderMS2bits
	/// \brief Decode MS 2 bits from byte

	class DecoderMS2bits: public Decoder {
	public:
		/// Constructor
		DecoderMS2bits();
		/// Destructor
		virtual ~DecoderMS2bits() {}

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get value of MS 2 bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int ms2bits() const;

	private:
		int num_;
	};

} /* namespace pcars */

#endif /* PCARS_DecoderMS2bits_H_ */
