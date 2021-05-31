#ifndef PCAR_DECODER_U32_H_
#define PCAR_DECODER_U32_H_

#include "../inc/decoder.h"

namespace pcars {

	/// \class DecoderU32
	/// \brief Decode 4 bytes into unsigned int

	class DecoderU32 : public Decoder {
	public:
		/// Constructor
		DecoderU32();
		/// Destructor
		virtual ~DecoderU32() {}

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
		
		unsigned int u32() const;

	private:
		unsigned int num_;
	};

}

#endif

