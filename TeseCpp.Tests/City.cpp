
#include "stdafx.h"

#include "City.h"

TeseCppTests::City::City()
{
}

TeseCppTests::City::City(String^ name, State^ state, long code)
{
	this->name = name;
	this->state = state;
	this->code = code;
}

String^ TeseCppTests::City::Name::get() {
	return this->name;
}

Void TeseCppTests::City::Name::set(String^ value) {
	this->name = value;
}

long TeseCppTests::City::Code::get() {
	return this->code;
}

Void TeseCppTests::City::Code::set(long value) {
	this->code = value;
}

TeseCppTests::State^ TeseCppTests::City::_State::get() {
	return this->state;
}

Void TeseCppTests::City::_State::set(State^ value) {
	this->state = value;
}
