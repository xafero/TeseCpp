
#pragma once

using namespace System;
using namespace System::Reflection;

namespace TeseCpp {

	[Serializable]
	public ref class TeseWriteException : Exception
	{
	public:
		TeseWriteException(Exception^ t);
		TeseWriteException(FieldInfo^ field, Exception^ e);
	};

}
