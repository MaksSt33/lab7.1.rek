#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.1.rek/lab7.1.rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71rek
{
	TEST_CLASS(UnitTest71rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 2;
			int colCount = 3;
			int** testMatrix = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				testMatrix[i] = new int[colCount];
			testMatrix[0][0] = 3;
			testMatrix[0][1] = 5;
			testMatrix[0][2] = 9;
			testMatrix[1][0] = 7;
			testMatrix[1][1] = 6;
			testMatrix[1][2] = 8;
			int S = 0;
			int k = 0;
			Calc(testMatrix, rowCount, colCount, S, k);
			Assert::AreEqual(24, S);
			Assert::AreEqual(4, k);
			Assert::AreEqual(0, testMatrix[0][0]);
			Assert::AreEqual(0, testMatrix[0][1]);
			Assert::AreEqual(0, testMatrix[0][2]);
			Assert::AreEqual(0, testMatrix[1][0]);

			for (int i = 0; i < rowCount; i++)
				delete[] testMatrix[i];
			delete[] testMatrix;
		}
	};
}

