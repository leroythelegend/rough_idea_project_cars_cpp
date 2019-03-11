#ifndef PCARS_DECODER_MS4BITS_H_
#define PCARS_DECODER_MS4BITS_H_

#include "decoder.h"

namespace pcars {

	/// \class DecoderMS4bits
	/// \brief Decode MS 4 bits from byte

	class DecoderMS4bits : public Decoder {
	public:
		/// Constructor
		DecoderMS4bits();
		/// Destructor
		virtual ~DecoderMS4bits();
		
		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get Most Significant 4bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int ms4bits() const;

	private:
		unsigned int num_;

	};

}

#endif

