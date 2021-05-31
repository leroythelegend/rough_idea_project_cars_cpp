#ifndef PCARS_DECODER_TOP_2BITS_H_
#define PCARS_DECODER_TOP_2BITS_H_

#include "../inc/decoder.h"

namespace pcars {

	/// \class DecoderTop2bits
	/// \brief Decode top 2 bits from byte

	class DecoderTop2bits : public Decoder {
	public:
		/// Constructor
		DecoderTop2bits();
		/// Destructor
		virtual ~DecoderTop2bits();

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get value of top 2 bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int top_2bit() const;

	private:
		unsigned int num_;
	};

}

#endif

