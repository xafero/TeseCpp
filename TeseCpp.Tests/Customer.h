
#include "Address.h"

#pragma once

using namespace System;
using namespace System::Numerics;
using namespace TeseCpp;

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
		Char sex;
		int houses;
		short pets;
		float crazyness;
		Byte bits;
		BigInteger sleep;
		Decimal awake;
		[ForceType(Detail = DateTime::typeid)]
		DateTime^ birth;
	public:
		Customer();
		Customer(long id, String^ firstName, String^ lastName, double money, bool male, 
			Char sex, int houses, short pets, float crazyness, Byte bits,
			BigInteger sleep, Decimal awake, DateTime^ birth, Address^ home);
		property long Id { long get(); void set(long value); }
		property String^ FirstName { String^ get(); void set(String^ value); }
		property String^ LastName { String^ get(); void set(String^ value); }
		property double Money { double get(); void set(double value); }
		property bool Male { bool get(); void set(bool value); }
		property Char Sex { Char get(); void set(Char value); }
		property int Houses { int get(); void set(int value); }
		property short Pets { short get(); void set(short value); }
		property float Crazyness { float get(); void set(float value); }
		property Byte Bits { Byte get(); void set(Byte value); }
		property BigInteger Sleep { BigInteger get(); void set(BigInteger value); }
		property Decimal Awake { Decimal get(); void set(Decimal value); }
		property DateTime^ Birth { DateTime^ get(); void set(DateTime^ value); }
		property Address^ Home { Address^ get(); void set(Address^ value); }
	};

}
