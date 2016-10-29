
#include "stdafx.h"

#include "Tese.h"

String^ TeseCpp::Tese::Serialize(Object^ object) 
{
	return object->ToString();
}

generic <typename T>
T TeseCpp::Tese::Deserialize(String^ txt) 
{
	return safe_cast<T>(txt);
}
