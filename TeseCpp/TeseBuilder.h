
#include "Tese.h"

#pragma once

using namespace System;

namespace TeseCpp {

	public ref class TeseBuilder 
	{
	public:
		TeseBuilder^ SkipNull(bool skipNull);
		Tese^ Create();
	};

}
