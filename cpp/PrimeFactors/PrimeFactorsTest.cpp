#include "PrimeFactors.h"
#include <vector>
#include <gtest/gtest.h>
#include <stdarg.h>

void assertEquals(std::vector<int> expected, std::vector<int> actual) {
	std::vector<int>::iterator eIter, aIter;
	for (eIter = expected.begin(), aIter = actual.begin(); eIter != expected.end()
			&& aIter != actual.end(); eIter++, aIter++) {
		ASSERT_EQ(*eIter, *aIter);
	}

	std::vector<int>::size_type expectedSize = expected.size();
	std::vector<int>::size_type actualSize = actual.size();
	ASSERT_EQ(expectedSize, actualSize);
}

std::vector<int> emptyList(void) {
	std::vector<int> expected;
	return expected;
}

std::vector<int> asList(int one) {
	std::vector<int> expected = emptyList();
	expected.push_back(one);
	return expected;
}

TEST(PrimeFactorsTest, testOne)
{
	assertEquals(emptyList(), PrimeFactors::generate(1));
}

TEST(PrimeFactorsTest, testTwo)
{
	assertEquals(asList(2), PrimeFactors::generate(2));
}

TEST(PrimeFactorsTest, testThree)
{
	assertEquals(asList(3), PrimeFactors::generate(3));
}

TEST(PrimeFactorsTest, testFour)
{
	int input[2] = { 2, 2 };
	std::vector<int> expected(input, input + sizeof(input) / sizeof(int));

	assertEquals(expected, PrimeFactors::generate(4));
}

TEST(PrimeFactorsTest, testSix)
{
	int input[2] = { 2, 3 };
	std::vector<int> expected(input, input + sizeof(input) / sizeof(int));

	assertEquals(expected, PrimeFactors::generate(6));
}

TEST(PrimeFactorsTest, testEight)
{
	int input[3] = { 2, 2, 2 };
	std::vector<int> expected(input, input + sizeof(input) / sizeof(int));

	assertEquals(expected, PrimeFactors::generate(8));
}

TEST(PrimeFactorsTest, testNine)
{
	int input[2] = { 3, 3 };
	std::vector<int> expected(input, input + sizeof(input) / sizeof(int));

	assertEquals(expected, PrimeFactors::generate(9));
}

