
#include "stdafx.h"

#include "TeseReadException.h"

TeseCpp::TeseReadException::TeseReadException(Exception^ t) : Exception("", t)
{
}
