
#include "stdafx.h"

#include "TeseBuilder.h"

TeseCpp::TeseBuilder^ TeseCpp::TeseBuilder::SkipNull(bool skipNull) {
	return this;
}

TeseCpp::Tese^ TeseCpp::TeseBuilder::Create() {
	return gcnew TeseCpp::Tese();
}
