/*
Given a year, report if it is a leap year.

The tricky thing here is that a leap year in the Gregorian calendar occurs:

on every year that is evenly divisible by 4
  except every year that is evenly divisible by 100
    unless the year is also evenly divisible by 400

For example, 1997 is not a leap year, but 1996 is. 1900 is not a leap year, but 2000 is.

If your language provides a method in the standard library that does this look-up, pretend it doesn't exist and implement it yourself.
*/

#include <gtest/gtest.h>

const size_t g_firstYearGregorianCallendar = 1583;
bool isLeapYear(int year)
{
    if(year<g_firstYearGregorianCallendar)
    {
        return false;
    }
    if(year%4 == 0)
    {
        return true;
    }
    return false;
}

TEST(funcLeapYearTest, YearMultipleFour_returnTrue)
{
    ASSERT_TRUE(isLeapYear(1996));
}

TEST(funcLeapYearTest, YearBeforeGregorianCallendar_returnFalse)
{
    ASSERT_FALSE(isLeapYear(1581));
}

TEST(funcLeapYearTest, YearNotMultipleFour_returnFalse)
{
    ASSERT_FALSE(isLeapYear(1997));
}

TEST(funcLeapYearTest, YearMultipleOneHundred_returnFalse)
{
    ASSERT_FALSE(isLeapYear(1900));
}
