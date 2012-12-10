#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <list>

using ::testing::ElementsAre;

std::list<int> PrimeFactors(int n)
{
    std::list<int> primes;

    for (int candidate = 2; n > 1; candidate++)
        for (; n % candidate == 0; n /=  candidate)
            primes.push_back(candidate);

    return primes;
}

TEST(PrimeFactors, One) {
    ASSERT_THAT(PrimeFactors(1), ElementsAre());
}

TEST(PrimeFactors, Two) {
    ASSERT_THAT(PrimeFactors(2), ElementsAre(2));
}

TEST(PrimeFactors, Three) {
    ASSERT_THAT(PrimeFactors(3), ElementsAre(3));
}

TEST(PrimeFactors, Four) {
    ASSERT_THAT(PrimeFactors(4), ElementsAre(2,2));
}

TEST(PrimeFactors, Six) {
    ASSERT_THAT(PrimeFactors(6), ElementsAre(2,3));
}

TEST(PrimeFactors, Eight) {
    ASSERT_THAT(PrimeFactors(8), ElementsAre(2,2,2));
}

TEST(PrimeFactors, Nine) {
    ASSERT_THAT(PrimeFactors(9), ElementsAre(3,3));
}
