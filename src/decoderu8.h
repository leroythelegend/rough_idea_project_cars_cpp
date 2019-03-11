#ifndef PCARS_DECODER_U8_H_
#define PCARS_DECODER_U8_H_

#include <cstdint>

#include "decoder.h"

namespace pcars {

	/// \class DecoderU8
	/// \brief Decode unsigned int

	class DecoderU8 : public Decoder {
	public:
		/// Constructor
		DecoderU8();
		/// Destructor
		virtual ~DecoderU8();

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get unsigned int
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int u8() const;

	private:
		uint8_t num_;
	};

}

#endif

