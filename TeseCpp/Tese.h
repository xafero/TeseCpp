
#include "TeseReadException.h"
#include "TeseWriteException.h"

#pragma once

using namespace System;
using namespace System::Collections;
using namespace System::Globalization;
using namespace System::IO;
using namespace System::Numerics;
using namespace System::Reflection;
using namespace System::Text;
using namespace Kajabity::Tools::Java;

namespace TeseCpp {

	public ref class Tese 
	{
	private:
		literal String^ emptyPrefix = "";
		Object^ DeserializeFields(String^ prefix, IDictionary^ props, Type^ type);
		Void DeserializeField(String^ prefix, Object^ obj, FieldInfo^ field, IDictionary^ props);
		bool FindLongerKey(IDictionary^ props, String^ shortKey);
		Object^ FromStr(String^ val, FieldInfo^ field);
		Void SerializeFields(String^ prefix, Object^ obj, IDictionary^ props);
		Void SerializeField(String^ prefix, Object^ obj, FieldInfo^ field, IDictionary^ props);
		String^ ToStr(Object^ value, FieldInfo^ field);
	public:
		String^ Serialize(Object^ obj);
		Void Serialize(Object^ obj, Stream^ writer);
		generic <typename T>
		T Deserialize(String^ text);
		generic <typename T>
		T Deserialize(Stream^ stream);
	};

}
