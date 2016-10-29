
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
