/*
Given a phrase, count the occurrences of each word in that phrase. Ignore whitespaces and punctual symbols
For example for the input "olly olly in come free please please let it be in such manner olly"
olly: 3
in: 2
come: 1
free: 1
please: 2
let: 1
it: 1
be: 1
manner: 1
such: 1
*/

#include <gtest/gtest.h>
#include <string>
#include <map>

const char SPACE = ' ';
const int startCount = 1;

std::map<std::string, int> funcWordCount(std::string str)
{
    std::map<std::string, int> allWords;
    if(str.empty())
    {
        return allWords;
    }
    std::size_t position = str.find(SPACE);
    if (position==std::string::npos)
    {
        allWords[str]=startCount;
    }
    else
    {
        if(allWords.count(str.substr(0,position)))
        {
            allWords[str.substr(0,position)]++;
        }
        else {
            allWords[str.substr(0,position)]=startCount;
        }
        size_t positionSecond = str.find(SPACE, position);
        if(allWords.count(str.substr(position+1, positionSecond)))
        {
            allWords[str.substr(position+1, positionSecond)]++;
        }
        else {
            allWords[str.substr(position+1, positionSecond)]=startCount;
        }
    }
    return allWords;
}

TEST(funcWordCount, NoWord)
{
     ASSERT_TRUE(funcWordCount("").empty());
}

TEST(funcWordCount, mapHasOneKey)
{
     ASSERT_EQ(funcWordCount("olly").size(), 1);
}

TEST(funcWordCount, stringWithOneWordAndSpace)
{
     ASSERT_EQ(funcWordCount("olly ")["olly"], 1);
}

TEST(funcWordCount, stringWithSameWord)
{
     ASSERT_EQ(funcWordCount("olly olly")["olly"], 2);
}
