
#include "stdafx.h"

#include "TeseBuilder.h"

TeseCpp::TeseBuilder^ TeseCpp::TeseBuilder::SkipNull(bool skipNull) {
	this->skipNull = skipNull;
	return this;
}

TeseCpp::Tese^ TeseCpp::TeseBuilder::Create() {
	return gcnew TeseCpp::Tese();
}

bool TeseCpp::TeseBuilder::IsSkipNull::get() {
	return this->skipNull;
}
