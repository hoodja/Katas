#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

int infer(char letter)
{
    if( 'V' == letter)
    {
        return 5;
    }
    else if( 'X' == letter)
    {
        return 10;
    }
    else if ('I' == letter)
    {
        return 1;
    }
}

int convert(std::string input)
{
    int result = 0;

    for (std::string::iterator current = input.begin(); current != input.end(); current++)
        result += infer(*current);

    return result;
}


TEST(RomanNumerals, One)
{
    ASSERT_EQ(1, convert("I"));
}

TEST(RomanNumerals, Two)
{
    ASSERT_EQ(2, convert("II"));
}

TEST(RomanNumerals, Three)
{
    ASSERT_EQ(3, convert("III"));
}

TEST(RomanNumberals, Five)
{
    ASSERT_EQ(5, convert("V"));
}

TEST(RomanNumerals, Six)
{
    ASSERT_EQ(6, convert("VI"));
}

TEST(RomanNumerals, Seven)
{
    ASSERT_EQ(7, convert("VII"));
}

TEST(RomanNumerals, Ten)
{
    ASSERT_EQ(10, convert("X"));
}

TEST(RomanNumerals, Fifteen)
{
    ASSERT_EQ(15, convert("XV"));
}

TEST(RomanNumerals, TwentyFive)
{
    ASSERT_EQ(25, convert("XXV"));
}

TEST(RomanNumerals, Four)
{
    ASSERT_EQ(4, convert("IV"));
}
