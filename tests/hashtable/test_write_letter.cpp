//
// Created by daniel on 2/09/23.
//
#include "gtest/gtest.h"
#include "hashtable.h"


TEST(TestCanWriteLetter, LetterCanBeWritten)
{
    std::string magazine {"welcome to real hell this day"};
    std::string letter {"hello world"};
    ASSERT_TRUE(itp::canWriteLetter(magazine, letter));
}


TEST(TestCanWriteLetter, LetterCannotBeWritten)
{
    std::string magazine {"Hello world"};
    std::string letter {"I like my two dogs"};
    ASSERT_FALSE(itp::canWriteLetter(magazine, letter));
}


TEST(TestCanWriteLetter, IgnoresPunctuationAndCasing)
{
    std::string magazine {"Welcome to real hell! This day."};
    std::string letter {"Hello World."};
    ASSERT_TRUE(itp::canWriteLetter(magazine, letter));
}
