
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
	};

}
