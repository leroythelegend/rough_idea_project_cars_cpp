#ifndef PCARS_DECODER_BOOL_U8_H_
#define PCARS_DECODER_BOOL_U8_H_

#include "decodercomposite.h"

#include "decodermsbbool.h"
#include "decoderls7bits.h"

namespace pcars {

	/// \class DecoderBoolU8
	/// \brief Decode bool from bit

	class DecoderBoolU8 : public DecoderComposite {
	public:
		/// Constructor
		DecoderBoolU8();
		/// Destructor
		virtual ~DecoderBoolU8() {}

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get MSB as bool
		///
		///
		/// \return value
		/// \throw nothing

		bool msb_bool() const;

		/// \brief Get value of 7 LSB bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int ls7_bits() const;

	private:
		DecoderMSBBool bool_;
		DecoderLS7bits num_;
	};

}

#endif

