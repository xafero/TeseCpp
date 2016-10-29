
#include "State.h"

#pragma once

using namespace System;
using namespace TeseCpp;

namespace TeseCppTests {

	public ref class City
	{
	private:
		String^ name;
		[ForceType(Detail = State::typeid)]
		State^ state;
		long code;
	public:
		City();
		City(String^ name, State^ state, long code);
		property String^ Name { String^ get(); void set(String^ value); }
		property State^ _State { State^ get(); void set(State^ value); }
		property long Code { long get(); void set(long value); }
	};

}
