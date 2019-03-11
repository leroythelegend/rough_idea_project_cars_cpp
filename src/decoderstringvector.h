#ifndef PCARS_DECODER_STRING_VECTOR_H_
#define PCARS_DECODER_STRING_VECTOR_H_

#include "decoder.h"

#include <string>
#include <vector>

namespace pcars {

	/// \class DecoderStringVector
	/// \brief Decode string vector

	class DecoderStringVector : public Decoder {
	public:
		using Num_Participants = int;

		/// Constructor
		///
		/// \param Number of Participants

		DecoderStringVector(Num_Participants);
		/// Destructro
		virtual ~DecoderStringVector();

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get string vector
		///
		///
		/// \return value
		/// \throw nothing

		Vector_String string_vector() const;

	private:
		Num_Participants numparticipants_;
		Vector_String stringvector_;
	};

}

#endif
