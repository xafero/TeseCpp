
#include "City.h"

#pragma once

using namespace System;

namespace TeseCppTests {

	public ref class Address
	{
	private:
		String^ street;
		int number;
		long postal;
		City^ city;
	public:
		Address();
		Address(String^ street, int number, long postal, City^ city);
		property String^ Street { String^ get(); void set(String^ value); }
		property int Number { int get(); void set(int value); }
		property long Postal { long get(); void set(long value); }
		property City^ _City { City^ get(); void set(City^ value); }
	};

}
