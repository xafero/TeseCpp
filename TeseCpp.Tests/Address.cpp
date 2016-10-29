
#include "stdafx.h"

#include "Address.h"

TeseCppTests::Address::Address()
{
}

TeseCppTests::Address::Address(String^ street, int number, long postal, City^ city)
{
	this->street = street;
	this->number = number;
	this->postal = postal;
	this->city = city;
}
