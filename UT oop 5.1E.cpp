#include "pch.h"
#include "CppUnitTest.h"
#include "../oop 5.1E/Exception.cpp"
#include "../oop 5.1E/FuzzyNumber.cpp"
#include "../oop 5.1E/InheritedException.cpp"
#include "../oop 5.1E/Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UToop51E
{
	TEST_CLASS(UToop51E)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			FuzzyNumber A(3.5, 1.2, 7.9), B(4.3, 2.0, 8.4);
			FuzzyNumber C = A + B;
			Assert::AreEqual(C.get_x(), 7.8);
		}
	};
}
