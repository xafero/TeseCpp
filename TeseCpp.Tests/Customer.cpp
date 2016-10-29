
#include "stdafx.h"

#include "Customer.h"

TeseCppTests::Customer::Customer() 
{
}

TeseCppTests::Customer::Customer(long id, String^ firstName, String^ lastName, 
	double money, bool male, char sex, int houses, short pets, float crazyness, 
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
