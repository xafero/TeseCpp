
#include "Address.h"

#pragma once

using namespace System;
using namespace System::Numerics;

namespace TeseCppTests {

	public ref class Customer
	{
	private:
		long id;
		String^ firstName;
		String^ lastName;
		double money;
		bool male;
		Address^ home;
		char sex;
		int houses;
		short pets;
		float crazyness;
		Byte bits;
		BigInteger sleep;
		Decimal awake;
		DateTime^ birth;
	public:
		Customer();
		Customer(long id, String^ firstName, String^ lastName, double money, bool male, 
			char sex, int houses, short pets, float crazyness, Byte bits,
			BigInteger sleep, Decimal awake, DateTime^ birth, Address^ home);
	};

}
