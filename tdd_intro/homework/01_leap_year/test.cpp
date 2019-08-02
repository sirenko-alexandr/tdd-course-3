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

const int GREGORIAN_CALENDAR_ESTABLISHMENT_YEAR = 1584;

bool isLeapYear(int year) {
    if (year < GREGORIAN_CALENDAR_ESTABLISHMENT_YEAR)
        return false;

    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

TEST(IS_LEAP_YEAR, WHEN_YEAR_IS_BEFORE_GREGORIAN_CALENDAR_THEN_RETURN_FALSE)
{
    ASSERT_FALSE(isLeapYear(1583));
}

TEST(IS_LEAP_YEAR, WHEN_YEAR_IS_NOT_DEVISIBLE_BY_4_THEN_RETURN_FALSE)
{
    ASSERT_FALSE(isLeapYear(1657));
}

TEST(IS_LEAP_YEAR, WHEN_YEAR_IS_DEVISIBLE_BY_100_THEN_RETURN_FALSE)
{
    ASSERT_FALSE(isLeapYear(1800));
}

TEST(IS_LEAP_YEAR, WHEN_YEAR_IS_DEVISIBLE_BY_400_THEN_RETURN_TRUE)
{
    ASSERT_TRUE(isLeapYear(2000));
}
