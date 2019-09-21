#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CommonFunction/Common.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest_Common)
	{
	public:
		
		TEST_METHOD(Split)
		{
			string str1 = "/A/B/C:123";
			string str2 = "/A/B/C/";
			string str3 = "A/B/C";
			string str4 = "A/B/C/";
			string str5 = "A//B/C";

			Common::Split(str1, "/");

			vector<string> strs = Common::Split(str1, "/");
			Assert::AreEqual(true, "A" == strs[0]);
			Assert::AreEqual(true, "B" == strs[1]);
			Assert::AreEqual(true, "C:123" == strs[2]);

			strs = Common::Split(str2, "/");
			Assert::AreEqual(true, "A" == strs[0]);
			Assert::AreEqual(true, "B" == strs[1]);
			Assert::AreEqual(true, "C" == strs[2]);
			strs = Common::Split(str3, "/");
			Assert::AreEqual(true, "A" == strs[0]);
			Assert::AreEqual(true, "B" == strs[1]);
			Assert::AreEqual(true, "C" == strs[2]);
			strs = Common::Split(str4, "/");
			Assert::AreEqual(true, "A" == strs[0]);
			Assert::AreEqual(true, "B" == strs[1]);
			Assert::AreEqual(true, "C" == strs[2]);
			strs = Common::Split(str5, "/");
			Assert::AreEqual(true, "A" == strs[0]);
			Assert::AreEqual(true, "B" == strs[1]);
			Assert::AreEqual(true, "C" == strs[2]);

			 
		}

	};
}