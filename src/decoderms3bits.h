#ifndef PCARS_DECODER_MS3BITS_H_
#define PCARS_DECODER_MS3BITS_H_

#include "decoder.h"

namespace pcars {

	/// \class DecoderMS3bits
	/// \brief Decode MS 3 bits from byte

	class DecoderMS3bits: public Decoder {
	public:
		/// Constructor
		DecoderMS3bits();
		/// Destructor
		virtual ~DecoderMS3bits();

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get value of MS 3 bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int ms3bits() const;

	private:
		unsigned int num_;
	};

}

#endif

