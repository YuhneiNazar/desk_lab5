#include "pch.h"
#include "CppUnitTest.h"
#include "../desk_lab5/desk_lab5.cpp"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
            char B[3] = { 'a', 'b', 'c' };
            char C[2] = { 'x', 'y' };
            string expected_output[] = { "axa", "axb", "axc", "aya", "ayb", "ayc", "bxa", "bxb", "bxc", "bya", "byb", "byc", "cxa", "cxb", "cxc", "cya", "cyb", "cyc" };

            std::stringstream buffer;
            std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

            zav1(B, C);
            std::cout.rdbuf(old_cout);
            std::string actual_output = buffer.str();

			for (int i = 0; i < 18; i++)
			{
				Assert::AreEqual(expected_output[i].c_str(), actual_output.substr(i * 4, 3).c_str());
			}
		}

		TEST_METHOD(TestMethod2)
		{
			int x = 3;
			std::istringstream input("abc");
			std::cin.rdbuf(input.rdbuf());

			std::string result = input.str();

			Assert::AreEqual(result.c_str(), "abc");
		}
	};
}
