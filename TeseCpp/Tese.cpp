
#include "stdafx.h"

#include "Tese.h"

String^ TeseCpp::Tese::Serialize(Object object) 
{
	return object.ToString();
}

Object TeseCpp::Tese::Deserialize(String^ object) 
{
	return object;
}
