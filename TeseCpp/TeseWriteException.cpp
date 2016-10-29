
#include "stdafx.h"

#include "TeseWriteException.h"

TeseCpp::TeseWriteException::TeseWriteException(Exception^ t) : Exception("", t)
{
}

TeseCpp::TeseWriteException::TeseWriteException(FieldInfo^ field, Exception^ e) 
	: Exception(field + "", e)
{
}
