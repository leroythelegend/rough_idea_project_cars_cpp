#include "decoderclassinfo.h"

namespace pcars {


DecoderClassInfo::DecoderClassInfo() {
	add(&classindex_);
	add(&name_);
}

unsigned int DecoderClassInfo::class_index() const {
	return classindex_.u32();
}

std::string DecoderClassInfo::name() const {
	return name_.char20();
}

}

