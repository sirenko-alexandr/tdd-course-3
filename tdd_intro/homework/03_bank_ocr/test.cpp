/*### Bank OCR

Your manager has recently purchased a machine that assists in reading letters and faxes sent in by branch offices. The machine scans the paper documents, and produces a file with a number of entries. You will write a program to parse this file.

#### Specification
#### User Story 1

The following format is created by the machine:
```
    _  _     _  _  _  _  _
  | _| _||_||_ |_   ||_||_|
  ||_  _|  | _||_|  ||_| _|
```
Each entry is 3 lines long, and each line has 27 characters. 3 lines of each entry contain an account number written using pipes and underscores.

Each account number should have 9 digits, all of which should be in the range 0-9. A normal file contains around 500 entries.

Write a program that can take this file and parse it into actual account numbers.

Example input and output
```
 _  _  _  _  _  _  _  _  _
| || || || || || || || || |
|_||_||_||_||_||_||_||_||_|

=> 000000000

  |  |  |  |  |  |  |  |  |
  |  |  |  |  |  |  |  |  |

=> 111111111

 _  _  _  _  _  _  _  _  _
 _| _| _| _| _| _| _| _| _|
|_ |_ |_ |_ |_ |_ |_ |_ |_

=> 222222222

 _  _  _  _  _  _  _  _  _
 _| _| _| _| _| _| _| _| _|
 _| _| _| _| _| _| _| _| _|

=> 333333333

|_||_||_||_||_||_||_||_||_|
  |  |  |  |  |  |  |  |  |

=> 444444444

 _  _  _  _  _  _  _  _  _
|_ |_ |_ |_ |_ |_ |_ |_ |_
 _| _| _| _| _| _| _| _| _|

=> 555555555

 _  _  _  _  _  _  _  _  _
|_ |_ |_ |_ |_ |_ |_ |_ |_
|_||_||_||_||_||_||_||_||_|

=> 666666666

 _  _  _  _  _  _  _  _  _
  |  |  |  |  |  |  |  |  |
  |  |  |  |  |  |  |  |  |

=> 777777777

 _  _  _  _  _  _  _  _  _
|_||_||_||_||_||_||_||_||_|
|_||_||_||_||_||_||_||_||_|

=> 888888888

 _  _  _  _  _  _  _  _  _
|_||_||_||_||_||_||_||_||_|
 _| _| _| _| _| _| _| _| _|

=> 999999999

    _  _     _  _  _  _  _
  | _| _||_||_ |_   ||_||_|
  ||_  _|  | _||_|  ||_| _|

=> 123456789
```
*/
#include <gtest/gtest.h>
#include <string>

const unsigned short g_digitLen = 3;
const unsigned short g_linesInDigit = 3;
struct Digit
{
    std::string lines[g_linesInDigit];
};

const unsigned short g_digitsOnDisplay = 9;
struct Display
{
    std::string lines[g_linesInDigit];
};

const Digit s_digit0 = { " _ ",
                         "| |",
                         "|_|"
                       };
const Digit s_digit1 = { "   ",
                         "  |",
                         "  |"
                       };
const Digit s_digit2 = { " _ ",
                         " _|",
                         "|_ "
                       };
const Digit s_digit3 = { " _ ",
                         " _|",
                         " _|"
                       };
const Digit s_digit4 = { "   ",
                         "|_|",
                         "  |"
                       };
const Digit s_digit5 = { " _ ",
                         "|_ ",
                         " _|"
                       };
const Digit s_digit6 = { " _ ",
                         "|_ ",
                         "|_|"
                       };
const Digit s_digit7 = { " _ ",
                         "  |",
                         "  |"
                       };
const Digit s_digit8 = { " _ ",
                         "|_|",
                         "|_|"
                       };
const Digit s_digit9 = { " _ ",
                         "|_|",
                         " _|"
                       };

const Display s_displayAll0 = { " _  _  _  _  _  _  _  _  _ ",
                                "| || || || || || || || || |",
                                "|_||_||_||_||_||_||_||_||_|"
};

const Display s_displayAll1 = { "                           ",
                                "  |  |  |  |  |  |  |  |  |",
                                "  |  |  |  |  |  |  |  |  |"
};

const Display s_displayAll2 = {  " _  _  _  _  _  _  _  _  _ ",
                                 " _| _| _| _| _| _| _| _| _|",
                                 "|_ |_ |_ |_ |_ |_ |_ |_ |_ "
};

const Display s_displayAll3 = { " _  _  _  _  _  _  _  _  _ ",
                                " _| _| _| _| _| _| _| _| _|",
                                " _| _| _| _| _| _| _| _| _|"
};

const Display s_displayAll4 = { "                           ",
                                "|_||_||_||_||_||_||_||_||_|",
                                "  |  |  |  |  |  |  |  |  |"
};

const Display s_displayAll5 = { " _  _  _  _  _  _  _  _  _ ",
                                "|_ |_ |_ |_ |_ |_ |_ |_ |_ ",
                                " _| _| _| _| _| _| _| _| _|"
};

const Display s_displayAll6 = { " _  _  _  _  _  _  _  _  _ ",
                                "|_ |_ |_ |_ |_ |_ |_ |_ |_ ",
                                "|_||_||_||_||_||_||_||_||_|"
};

const Display s_displayAll7 = { " _  _  _  _  _  _  _  _  _ ",
                                "  |  |  |  |  |  |  |  |  |",
                                "  |  |  |  |  |  |  |  |  |"
};

const Display s_displayAll8 = { " _  _  _  _  _  _  _  _  _ ",
                                "|_||_||_||_||_||_||_||_||_|",
                                "|_||_||_||_||_||_||_||_||_|"
};

const Display s_displayAll9 = { " _  _  _  _  _  _  _  _  _ ",
                                "|_||_||_||_||_||_||_||_||_|",
                                " _| _| _| _| _| _| _| _| _|"
};

const Display s_display123456789 = { "    _  _     _  _  _  _  _ ",
                                     "  | _| _||_||_ |_   ||_||_|",
                                     "  ||_  _|  | _||_|  ||_| _|"
};

static std::array<Digit, 10> s_allDigits {s_digit0, s_digit1, s_digit2,
                                          s_digit3, s_digit4, s_digit5,
                                          s_digit6, s_digit7, s_digit8,
                                          s_digit9};

bool IsEqual(const Digit& digit, const Digit& another)
{
    for (int i = 0; i < g_linesInDigit; ++i)
    {
        if (digit.lines[i] != another.lines[i])
        {
            return false;
        }
    }
    return true;
}

unsigned short GetNumberByDigit(const Digit& digit)
{
    for (unsigned short i = 0; i < s_allDigits.size(); ++i)
    {
        if (IsEqual(digit, s_allDigits[i]))
        {
            return i;
        }
    }
    throw std::runtime_error("Nothing was found.");
}

std::vector<Digit> GetDigits(const Display& display)
{
    std::vector<Digit> digits;

    for (unsigned short i = 0; i < g_digitsOnDisplay * g_digitLen; i += g_digitLen)
    {
        Digit digit {display.lines[0].substr(i, g_digitLen),
                     display.lines[1].substr(i, g_digitLen),
                     display.lines[2].substr(i, g_digitLen)};
        digits.push_back(digit);
    }

    return digits;
}

std::string GetNumbers(const Display& display)
{
    auto digits = GetDigits(display);
    std::string numbers = "";

    for (const auto& digit : digits)
    {
        auto number = GetNumberByDigit(digit);
        numbers += std::to_string(number);
    }

    return numbers;
}

TEST(BankNumbers, displayAll0)
{
    EXPECT_EQ("000000000", GetNumbers(s_displayAll0));
}

TEST(BankNumbers, displayAll1)
{
    EXPECT_EQ("111111111", GetNumbers(s_displayAll1));
}

TEST(BankNumbers, display123456789)
{
    EXPECT_EQ("123456789", GetNumbers(s_display123456789));
}
