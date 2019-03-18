#include "decoder60classinfo.h"

namespace pcars {

Decoder60ClassInfo::Decoder60ClassInfo()
	: class_info_(60) {
	for (unsigned int i = 0; i < class_info_.size(); ++i) {
		add(&class_info_.at(i));
	}
}

Decoder60ClassInfo::Vector_Class_Info Decoder60ClassInfo::class_info() const {
	return class_info_;
}

}

