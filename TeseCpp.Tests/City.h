
#include "State.h"

#pragma once

using namespace System;

namespace TeseCppTests {

	public ref class City
	{
	private:
		String^ name;
		State^ state;
		long code;
	public:
		City();
		City(String^ name, State^ state, long code);
	};

}
