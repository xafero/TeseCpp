
#include "stdafx.h"

#include "Customer.h"

TeseCppTests::Customer::Customer() 
{
}

TeseCppTests::Customer::Customer(long id, String^ firstName, String^ lastName, 
	double money, bool male, Char sex, int houses, short pets, float crazyness, 
	Byte bits, BigInteger sleep, Decimal awake, DateTime^ birth, Address^ home)
{
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->money = money;
	this->male = male;
	this->sex = sex;
	this->houses = houses;
	this->pets = pets;
	this->crazyness = crazyness;
	this->bits = bits;
	this->sleep = sleep;
	this->awake = awake;
	this->birth = birth;
	this->home = home;
}

long TeseCppTests::Customer::Id::get() { return this->id; }
Void TeseCppTests::Customer::Id::set(long value) { this->id = value; }

String^ TeseCppTests::Customer::FirstName::get() { return this->firstName; }
Void TeseCppTests::Customer::FirstName::set(String^ value) { this->firstName = value; }

String^ TeseCppTests::Customer::LastName::get() { return this->lastName; }
Void TeseCppTests::Customer::LastName::set(String^ value) { this->lastName = value; }

double TeseCppTests::Customer::Money::get() { return this->money; }
Void TeseCppTests::Customer::Money::set(double value) { this->money = value; }

bool TeseCppTests::Customer::Male::get() { return this->male; }
Void TeseCppTests::Customer::Male::set(bool value) { this->male = value; }

Char TeseCppTests::Customer::Sex::get() { return this->sex; }
Void TeseCppTests::Customer::Sex::set(Char value) { this->sex = value; }

int TeseCppTests::Customer::Houses::get() { return this->houses; }
Void TeseCppTests::Customer::Houses::set(int value) { this->houses = value; }

short TeseCppTests::Customer::Pets::get() { return this->pets; }
Void TeseCppTests::Customer::Pets::set(short value) { this->pets = value; }

float TeseCppTests::Customer::Crazyness::get() { return this->crazyness; }
Void TeseCppTests::Customer::Crazyness::set(float value) { this->crazyness = value; }

Byte TeseCppTests::Customer::Bits::get() { return this->bits; }
Void TeseCppTests::Customer::Bits::set(Byte value) { this->bits = value; }

BigInteger TeseCppTests::Customer::Sleep::get() { return this->sleep; }
Void TeseCppTests::Customer::Sleep::set(BigInteger value) { this->sleep = value; }

Decimal TeseCppTests::Customer::Awake::get() { return this->awake; }
Void TeseCppTests::Customer::Awake::set(Decimal value) { this->awake = value; }

DateTime^ TeseCppTests::Customer::Birth::get() { return this->birth; }
Void TeseCppTests::Customer::Birth::set(DateTime^ value) { this->birth = value; }

TeseCppTests::Address^ TeseCppTests::Customer::Home::get() { return this->home; }
Void TeseCppTests::Customer::Home::set(Address^ value) { this->home = value; }
