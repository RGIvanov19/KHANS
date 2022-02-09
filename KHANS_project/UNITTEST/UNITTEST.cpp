#include "pch.h"
#include "CppUnitTest.h"
#include "..\KHANS_project\KHANS_project.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UNITTEST
{
	TEST_CLASS(UNITTEST)
	{
	public:
		
            BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnDecToBin)
            TEST_OWNER(L"YGDimitrov19")
            TEST_PRIORITY("Low")
            END_TEST_METHOD_ATTRIBUTE()
            TEST_METHOD(expectToReturnDecToBin)
        {
            int n = 5;
           

            bool result = numToGray(n);

            Assert::AreEqual(true, result);
        }
	};
}
