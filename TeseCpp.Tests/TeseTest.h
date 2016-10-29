
#pragma once

using namespace System;
using namespace NUnit::Framework;
using namespace TeseCpp;

namespace TeseCppTests {

	[TestFixture]
	public ref class TeseTest 
	{
	private:
		Tese tese;
		String^ Deflatten(String^ txt);
		String^ Flatten(String^ txt);
		literal String^ txt1 = ".firstName=Harry ~ .money=123.89 ~ .pets=13 ~ .houses=42 ~ .home.city.state=IA ~ .home.street=West Ohio Street ~ .home.city.name=Ankeny ~ .sex=m ~ .lastName=Johnson ~ .bits=7 ~ .home.postal=50023 ~ .sleep=10 ~ .home.city.code=1 ~ .id=1 ~ .crazyness=97.5 ~ .male=True ~ .home.number=22 ~ .awake=1 ~ .birth=1970-02-19T02:17:29.348+01:00";
		literal __int64 secSinceEpoch = 621355968000000000L;
		literal int factor = 10000;
	public:
		[SetUp]
		Void TestSetup();
		[TearDown]
		Void TestTeardown();
		[Test]
		Void TestDeserialize();
		[Test]
		Void TestSerialize();
	};

}
