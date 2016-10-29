
#include "Tese.h"

#pragma once

using namespace System;

namespace TeseCpp {

	public ref class TeseBuilder 
	{
	private:
		bool skipNull;
	public:
		TeseBuilder^ SkipNull(bool skipNull);
		Tese^ Create();
		property bool IsSkipNull { bool get(); } 
	};

}
