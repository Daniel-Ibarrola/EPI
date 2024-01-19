//
// Created by DanielIbarrola on 1/15/2024.
//
#include "arrays.h"
#include "gtest/gtest.h"


TEST(DutchFlagPartition, Test1)
{
    std::vector<int> array {0, 1, 2, 0, 2, 1, 1};
    std::size_t pivot {3};

    epi::dutchFlagPartition(array, pivot);

    std::vector<int> expected {0, 0, 1, 2, 2, 1, 1};
    ASSERT_EQ(array, expected);
}


TEST(DutchFlagPartition, Test2)
{
    std::vector<int> array {0, 1, 2, 0, 2, 1, 1};
    std::size_t pivot {2};

    epi::dutchFlagPartition(array, pivot);

    std::vector<int> expected {0, 1, 0, 1, 1, 2, 2};
    ASSERT_EQ(array, expected);
}


TEST(IncrementInteger, Sums1)
{
    std::vector<int> num {1, 2, 9};
    std::vector<int> plusOne {epi::incrementInteger(num)};

    std::vector<int> expected {1, 3, 0};
    ASSERT_EQ(plusOne, expected);
}


TEST(IncrementInteger, NumberIncreasesDigitSize)
{
    std::vector<int> num {9, 9, 9, 9};
    std::vector<int> plusOne {epi::incrementInteger(num)};

    std::vector<int> expected {1, 0, 0, 0, 0};
    ASSERT_EQ(plusOne, expected);
}


TEST(IncrementInteger, EmptyArray)
{
    std::vector<int> num {};
    std::vector<int> plusOne {epi::incrementInteger(num)};

    ASSERT_TRUE(plusOne.empty());
}


TEST(PadWithZerosTest, HandlesNonEmptyVector) {
    std::vector<int> vec{1, 2, 3};
    auto result = epi::padWithZeros(vec, 5);
    std::vector<int> expected{0, 0, 1, 2, 3};
    ASSERT_EQ(result, expected);
}

TEST(PadWithZerosTest, HandlesAlreadySufficientSize) {
    std::vector<int> vec{1, 2, 3, 4, 5};
    auto result = epi::padWithZeros(vec, 5);
    ASSERT_EQ(result, vec);
}

TEST(PadWithZerosTest, HandlesEmptyVector) {
    std::vector<int> vec{};
    auto result = epi::padWithZeros(vec, 3);
    std::vector<int> expected{0, 0, 0};
    ASSERT_EQ(result, expected);
}

TEST(PadWithZerosTest, HandlesFinalSizeLessThanVecSize) {
    std::vector<int> vec{1, 2, 3};
    auto result = epi::padWithZeros(vec, 2); // Should return the original vector as is
    ASSERT_EQ(result, vec);
}


TEST(AddIntegers, SmallNumbers)
{
    std::vector<int> num1 {1, 2, 3};
    std::vector<int> num2 {4, 5, 6};
    std::vector<int> result {epi::addIntegers(num1, num2)};

    std::vector<int> expected {5, 7, 9};
    ASSERT_EQ(expected, result);
}


TEST(AddIntegers, LargerNumbers)
{
    std::vector<int> num1 {9, 9, 9};
    std::vector<int> num2 {9, 9, 9};
    std::vector<int> result {epi::addIntegers(num1, num2)};

    std::vector<int> expected {1,9,9,8};
    ASSERT_EQ(expected, result);
}


TEST(MultiplyIntegers, PositiveNumbers)
{
    std::vector<int> num {1, 4, 2};
    std::vector<int> multiplier {9, 2};
    std::vector<int> result {epi::multiplyIntegers(num, multiplier)};

    std::vector<int> expected {1, 3, 0, 6, 4};
    ASSERT_EQ(result, expected);
}


TEST(MultiplyIntegers, PositiveAndNegative)
{
    std::vector<int> num {1, 9, 3};
    std::vector<int> multiplier {-7, 6, 1};
    std::vector<int> result {epi::multiplyIntegers(num, multiplier)};

    std::vector<int> expected {-1, 4, 6, 8, 7, 3};
    ASSERT_EQ(result, expected);
}


TEST(MultiplyIntegers, NegativeNumbers)
{
    std::vector<int> num {-1, 4, 2};
    std::vector<int> multiplier {-2, 3, 5};
    std::vector<int> result {epi::multiplyIntegers(num, multiplier)};

    std::vector<int> expected {3, 3, 3, 7, 0};
    ASSERT_EQ(result, expected);
}


TEST(MultiplyIntegers, LargeNumbers)
{
    std::vector<int> num {1, 9, 3, 7, 0, 7, 7, 2, 1};
    std::vector<int> multiplier {-7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7};
    std::vector<int> result {epi::multiplyIntegers(num, multiplier)};

    std::vector<int> expected {-1, 4, 7, 5, 7, 3, 9, 5, 2, 5, 8, 9, 6, 7, 6, 4, 1, 2, 9, 2, 7};
    ASSERT_EQ(result, expected);
}


TEST(MultiplyIntegers, FactorOrderDoesntAffectProduct)
{
    std::vector<int> num {3, 4, 5};
    std::vector<int> multiplier {4, 2};

    std::vector<int> result1 {epi::multiplyIntegers(num, multiplier)};
    std::vector<int> result2 {epi::multiplyIntegers(multiplier, num)};

    std::vector<int> expected {1, 4, 4, 9, 0};
    ASSERT_EQ(result1, result2);
    ASSERT_EQ(result1, expected);
}


TEST(MultiplyIntegers, ANumberIsEmptyReturnsEmpty)
{
    std::vector<int> num {1, 9, 3};
    std::vector<int> multiplier {};
    std::vector<int> result {epi::multiplyIntegers(num, multiplier)};

    ASSERT_TRUE(result.empty());

    result = epi::multiplyIntegers(multiplier, num);
    ASSERT_TRUE(result.empty());
}


TEST(RemoveDuplicatesFromSortedArray, DuplicatesAreRemoved)
{
    std::vector<int> array {2, 3, 5, 5, 7, 11, 11, 11, 13};
    std::vector<int> noDuplicates {epi::removeDuplicates(array)};
    std::vector<int> expected {2, 3, 5, 7, 11, 13};
    ASSERT_EQ(noDuplicates, expected);
}


TEST(RemoveDuplicatesFromSortedArray, DoesntModifyArratIfNoDuplicates)
{
    std::vector<int> array {2, 3, 4, 5};
    std::vector<int> noDuplicates {epi::removeDuplicates(array)};
    std::vector<int> expected {2, 3, 4, 5};
    ASSERT_EQ(noDuplicates, expected);
}


TEST(RemoveDuplicatesFromSortedArray, EmptyArray)
{
    std::vector<int> array {};
    std::vector<int> noDuplicates {epi::removeDuplicates(array)};
    ASSERT_TRUE(noDuplicates.empty());
}


TEST(NumberOfDuplicates, DuplicatesAreRemoved)
{
    std::vector<int> array {2, 3, 5, 5, 7, 11, 11, 11, 13};
    int numDuplicates {epi::numDuplicates(array)};
    ASSERT_EQ(numDuplicates, 3);
}


TEST(NumberOfDuplicates, DoesntModifyArratIfNoDuplicates)
{
    std::vector<int> array {2, 3, 4, 5};
    int numDuplicates {epi::numDuplicates(array)};
    ASSERT_EQ(numDuplicates, 0);
}


TEST(NumberOfDuplicates, EmptyArray)
{
    std::vector<int> array {};
    int numDuplicates {epi::numDuplicates(array)};
    ASSERT_EQ(numDuplicates, 0);
}


TEST(BuyAndSellStock, ComputesMaxProfit)
{
    std::vector<int> prices {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    int maxProfit {epi::maxProfit(prices)};
    ASSERT_EQ(maxProfit, 30);
}


TEST(BuyAndSellStock, NoProfitPossible)
{
    std::vector<int> prices {200, 150, 130};
    int maxProfit {epi::maxProfit(prices)};
    ASSERT_EQ(maxProfit, 0);
}
