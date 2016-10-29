
#include "stdafx.h"

#include "TeseTest.h"

Void TeseCppTests::TeseTest::TestSetup() {
	tese = (gcnew TeseBuilder())->SkipNull(true)->Create();
}

Void TeseCppTests::TeseTest::TestTeardown() {
	tese = nullptr;
}

Void TeseCppTests::TeseTest::TestDeserialize() {
}

String^ TeseCppTests::TeseTest::Deflatten(String^ txt) {
	String^ nl = Environment::NewLine;
	txt = txt->Replace(" ~ ", nl);
	return txt;
}

Void TeseCppTests::TeseTest::TestSerialize() {
}

String^ TeseCppTests::TeseTest::Flatten(String^ txt) {
	String^ nl = Environment::NewLine;
	txt = txt->Split(gcnew array<String^> { nl }, 2, StringSplitOptions::None)[1]->Trim();
	txt = txt->Replace(nl, " ~ ");
	return txt;
}
