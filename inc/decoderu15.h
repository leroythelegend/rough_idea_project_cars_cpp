#ifndef PCARS_DECODER_U15_H_
#define PCARS_DECODER_U15_H_

#include <cstdint>

#include "../inc/decoder.h"

namespace pcars {

	/// \class DecoderU15
	/// \brief Decode 15 bits into unsigned int

	class DecoderU15 : public Decoder {
	public:
		/// Constructor
		DecoderU15();
		/// Destructor
		virtual ~DecoderU15();

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
		
		unsigned int u15() const;

	private:
		uint16_t num_;
	};

}

#endif

