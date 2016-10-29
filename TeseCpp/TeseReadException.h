
#pragma once

using namespace System;

namespace TeseCpp {

	[Serializable]
	public ref class TeseReadException : Exception
	{
	public:
		TeseReadException(Exception^ t);
	};

}
