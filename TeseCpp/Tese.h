
#pragma once

using namespace System;

namespace TeseCpp {

	public ref class Tese 
	{
	private:
		literal String^ emptyPrefix = "";
	public:
		String^ Serialize(Object^ obj);
		generic <typename T>
		T Deserialize(String^ txt);
	};

}
