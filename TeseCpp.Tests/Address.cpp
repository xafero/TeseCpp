
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

String^ TeseCppTests::Address::Street::get() {
	return this->street;
}

Void TeseCppTests::Address::Street::set(String^ value) {
	this->street = value;
}

long TeseCppTests::Address::Postal::get() {
	return this->postal;
}

Void TeseCppTests::Address::Postal::set(long value) {
	this->postal = value;
}

int TeseCppTests::Address::Number::get() {
	return this->number;
}

Void TeseCppTests::Address::Number::set(int value) {
	this->number = value;
}

TeseCppTests::City^ TeseCppTests::Address::_City::get() {
	return this->city;
}

Void TeseCppTests::Address::_City::set(City^ value) {
	this->city = value;
}
