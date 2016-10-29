
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
