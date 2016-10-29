
#pragma once

using namespace System;
using namespace NUnit::Framework;

namespace TeseCppTests {

	[TestFixture]
	public ref class TeseTest 
	{
	public:
		[SetUp]
		void TestSetup();
		[TearDown]
		void TestTeardown();
		[Test]
		void TestDeserialize();
		[Test]
		void TestSerialize();
	};

}
