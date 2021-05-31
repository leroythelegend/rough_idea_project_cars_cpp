#ifndef PCARS_DECODER_U16_H_
#define PCARS_DECODER_U16_H_

#include <cstdint>

#include "../inc/decoder.h"

namespace pcars {

	/// \class DecoderU16
	/// \brief Decode 2 bytes into unsigned int

	class DecoderU16 : public Decoder {
	public:
		/// Constructor
		DecoderU16();
		/// Destructor
		virtual ~DecoderU16();

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
		
		unsigned int u16() const;

	private:
		uint16_t num_;
	};

}

#endif

