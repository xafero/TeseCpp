
#pragma once

using namespace System;

namespace TeseCpp {
	
	[AttributeUsage(AttributeTargets::Field)]
	public ref class ForceTypeAttribute : public Attribute {
		public:
		   ForceTypeAttribute() {}
		   property Type^ Detail;
	};

}
