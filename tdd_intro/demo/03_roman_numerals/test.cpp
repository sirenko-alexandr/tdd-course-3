/*
Write a function to convert from normal numbers to Roman Numerals.

The Romans wrote numbers using letters - I, V, X, L, C, D, M. (converter http://www.novaroma.org/via_romana/numbers.html)

There is no need to be able to convert numbers larger than about 3000. (The Romans themselves didn't tend to go any higher)

Wikipedia says: Modern Roman numerals ... are written by expressing each digit separately starting with the left most digit and skipping any digit with a value of zero.

To see this in practice, consider the example of 1990.
In Roman numerals 1990 is MCMXC:
1000=M 900=CM 90=XC

2008 is written as MMVIII:
2000=MM 8=VIII

1998 is written as MCMXCVIII.
*/

#include <gtest/gtest.h>
#include <stdexcept>

static std::array<std::pair<int, std::string>, 7> arabicRomanPairs {std::make_pair<int, std::string>(1000, "M"),
                                                                    std::make_pair<int, std::string>(500, "D"),
                                                                    std::make_pair<int, std::string>(100, "C"),
                                                                    std::make_pair<int, std::string>(50, "L"),
                                                                    std::make_pair<int, std::string>(10, "X"),
                                                                    std::make_pair<int, std::string>(5, "V"),
                                                                    std::make_pair<int, std::string>(1, "I")};

static std::array<std::pair<int, std::string>, 3> reversePairs {std::make_pair<int, std::string>(100, "C"),
                                                                std::make_pair<int, std::string>(10, "X"),
                                                                std::make_pair<int, std::string>(1, "I")};

bool isPartOfNumber(const int number, const int part)
{
    return number - part >= 0;
}

bool isPossibleReverseNumber(const int mainNumber, const int possibleReverseNumber)
{
    return mainNumber - possibleReverseNumber > 0;
}

std::pair<int, std::string> tryToGetReversePair(const int number, const std::pair<int, std::string>& mainPair)
{
    for (const auto& reversePair: reversePairs)
    {
        if (!isPossibleReverseNumber(mainPair.first, reversePair.first))
        {
            continue;
        }

        int compoundNumber = mainPair.first - reversePair.first;
        auto compoudRomanNumber = reversePair.second + mainPair.second;

        if (isPartOfNumber(number, compoundNumber))
        {
            return std::make_pair<int, std::string>(std::move(compoundNumber), std::move(compoudRomanNumber));
        }
    }

    return std::make_pair<int, std::string>(0, "");
}

std::pair<int, std::string> getPairByNumber(const int number)
{
    for (const auto& pair: arabicRomanPairs)
    {
        if (isPartOfNumber(number, pair.first))
        {
            return pair;
        }

        auto reversePair = tryToGetReversePair(number, pair);
        if (reversePair.first != 0)
        {
            return reversePair;
        }
    }

    throw std::runtime_error("Not found number.");
}

std::string convertToRomanFromArabic(const int arabicNumber)
{
    std::string romanNumber;
    int operationalArabicNumber = arabicNumber;

    while (operationalArabicNumber)
    {
        auto pair = getPairByNumber(operationalArabicNumber);

        operationalArabicNumber -= pair.first;
        romanNumber += pair.second;
    }

    return romanNumber;
}

TEST(RomanNumbers, ConvertSimpleNumbers)
{
    for (const auto& arabicRomanPair: arabicRomanPairs)
    {
        EXPECT_EQ(arabicRomanPair.second, convertToRomanFromArabic(arabicRomanPair.first));
    }
}

TEST(RomanNumbers, ComplexNumbers)
{
    const std::map<int, std::string> complexNumbers {std::make_pair<int, std::string>(2, "II"),
                                                     std::make_pair<int, std::string>(6, "VI"),
                                                     std::make_pair<int, std::string>(11, "XI"),
                                                     std::make_pair<int, std::string>(60, "LX"),
                                                     std::make_pair<int, std::string>(110, "CX"),
                                                     std::make_pair<int, std::string>(600, "DC"),
                                                     std::make_pair<int, std::string>(1100, "MC")};
    for (const auto& arabicRomanPair: complexNumbers)
    {
        EXPECT_EQ(arabicRomanPair.second, convertToRomanFromArabic(arabicRomanPair.first));
    }
}

TEST(RomanNumbers, ComplexNumbersWithReverseOrder)
{
    const std::map<int, std::string> complexNumbers {std::make_pair<int, std::string>(4, "IV"),
                                                     std::make_pair<int, std::string>(9, "IX"),
                                                     std::make_pair<int, std::string>(40, "XL"),
                                                     std::make_pair<int, std::string>(90, "XC"),
                                                     std::make_pair<int, std::string>(400, "CD"),
                                                     std::make_pair<int, std::string>(900, "CM")};
    for (const auto& arabicRomanPair: complexNumbers)
    {
        EXPECT_EQ(arabicRomanPair.second, convertToRomanFromArabic(arabicRomanPair.first));
    }
}

TEST(RomanNumbers, TaskData)
{
    const std::map<int, std::string> complexNumbers {std::make_pair<int, std::string>(1990, "MCMXC"),
                                                     std::make_pair<int, std::string>(2008, "MMVIII"),
                                                     std::make_pair<int, std::string>(2000, "MM"),
                                                     std::make_pair<int, std::string>(8, "VIII"),
                                                     std::make_pair<int, std::string>(1998, "MCMXCVIII")};
    for (const auto& arabicRomanPair: complexNumbers)
    {
        EXPECT_EQ(arabicRomanPair.second, convertToRomanFromArabic(arabicRomanPair.first));
    }
}
