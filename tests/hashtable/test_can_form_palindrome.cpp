//
// Created by daniel on 1/09/23.
//

#include "gtest/gtest.h"
#include "hashtable.h"


TEST(CanFormPalindrome, Palindrome1)
{
    std::string str {"edified"};  // Palindrome deified
    ASSERT_TRUE(itp::canFormPalindrome(str));
}


TEST(CanFormPalindrome, Palindrome2)
{
    std::string str {"aa"};
    ASSERT_TRUE(itp::canFormPalindrome(str));
}


TEST(CanFormPalindrome, Palindrome3)
{
    std::string str {"evlel"};  // Palindrome level
    ASSERT_TRUE(itp::canFormPalindrome(str));
}


TEST(CanFormPalindrome, Palindrome4)
{
    std::string str {"bafarboofoo"}; // Palindrome foobaraboof
    ASSERT_TRUE(itp::canFormPalindrome(str));
}


TEST(CannotFormPalindorme, NonPalindorome1)
{
    std::string str {"ab"};
    ASSERT_FALSE(itp::canFormPalindrome(str));
}


TEST(CannotFormPalindorme, NonPalindorome2)
{
    std::string str {"car"};
    ASSERT_FALSE(itp::canFormPalindrome(str));
}


TEST(CanFormPalindrome, EmptyString)
{
    std::string str;
    ASSERT_TRUE(itp::canFormPalindrome(str));
}
