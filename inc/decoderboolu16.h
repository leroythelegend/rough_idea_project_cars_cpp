#ifndef PCARS_DECODER_BOOL_U16_H_
#define PCARS_DECODER_BOOL_U16_H_

#include "../inc/decodercomposite.h"

#include "../inc/decodermsbbool.h"
#include "../inc/decoderu15.h"

namespace pcars {

	/// \class DecoderBoolU16
	/// \brief Decode MSB bit from 2 bytes

	class DecoderBoolU16 : public DecoderComposite {
	public:
		/// Constructor
		DecoderBoolU16();
		/// Destructor
		virtual ~DecoderBoolU16() {}

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
		
		/// \brief Get value of 15 LSB bits
		///
		///
		/// \return value
		/// \throw nothing
		
		unsigned int u15() const;

	private:
		DecoderMSBBool bool_;
		DecoderU15 num_;
	};

}

#endif

