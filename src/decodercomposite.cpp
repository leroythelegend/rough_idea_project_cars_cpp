#include "../inc/decodercomposite.h"

namespace pcars {

void DecoderComposite::decode(const PCars_Data & data, Position & position) {
	for (iter_ = decoders_.begin(); iter_ != decoders_.end(); iter_++) {
		(*iter_)->decode(data, position);
	}
}

void DecoderComposite::add(Decoder * decoder) {
	decoders_.push_back(decoder);
}

}

