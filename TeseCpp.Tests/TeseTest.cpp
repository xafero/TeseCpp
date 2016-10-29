
#include "stdafx.h"

#include "TeseTest.h"

Void TeseCppTests::TeseTest::TestSetup() {
	tese = (gcnew TeseBuilder())->SkipNull(true)->Create();
}

Void TeseCppTests::TeseTest::TestTeardown() {
	tese = nullptr;
}

Void TeseCppTests::TeseTest::TestDeserialize() {
	Customer^ cus = tese->Deserialize<Customer^>(Deflatten(txt1));
	Assert::AreEqual(1, cus->Id);
	Assert::AreEqual("Harry", cus->FirstName);
	Assert::AreEqual("Johnson", cus->LastName);
	Assert::AreEqual(123.89, cus->Money);
	Assert::AreEqual(true, cus->Male);
	Assert::AreEqual('m', cus->Sex);
	Assert::AreEqual(42, cus->Houses);
	Assert::AreEqual(13, cus->Pets);
	Assert::AreEqual(97.5f, cus->Crazyness);
	Assert::AreEqual((Byte)7, cus->Bits);
	Assert::AreEqual(BigInteger::One * 10, cus->Sleep);
	Assert::AreEqual(Decimal::One, cus->Awake);			
	Assert::AreEqual(4238249348L, (cus->Birth->Ticks - secSinceEpoch) / factor);
	Assert::AreEqual(22, cus->Home->Number);
	Assert::AreEqual(50023, cus->Home->Postal);
	Assert::AreEqual("West Ohio Street", cus->Home->Street);
	Assert::AreEqual(1, cus->Home->_City->Code);
	Assert::AreEqual("Ankeny", cus->Home->_City->Name);
	Assert::AreEqual(State::IA, cus->Home->_City->_State);
}

String^ TeseCppTests::TeseTest::Deflatten(String^ txt) {
	String^ nl = Environment::NewLine;
	txt = txt->Replace(" ~ ", nl);
	return txt;
}

Void TeseCppTests::TeseTest::TestSerialize() {
	Customer^ cus = gcnew Customer(1, "Harry", "Johnson", 123.89, true, 'm', 42, (short)13,
				               97.5f, (Byte)7, BigInteger::One * 10, Decimal::One, 
				               gcnew DateTime((4238249348L * factor) + secSinceEpoch + (36000000000L)),
				               gcnew Address("West Ohio Street", 22, 50023, 
				               gcnew City("Ankeny", State::IA, 1L)));
	String^ txt = Flatten(tese->Serialize(cus));		
	Assert::AreEqual(txt1, txt);
}

String^ TeseCppTests::TeseTest::Flatten(String^ txt) {
	String^ nl = Environment::NewLine;
	txt = txt->Split(gcnew array<String^> { nl }, 2, StringSplitOptions::None)[1]->Trim();
	txt = txt->Replace(nl, " ~ ");
	return txt;
}
