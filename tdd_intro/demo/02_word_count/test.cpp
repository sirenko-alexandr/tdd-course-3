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

void changeCountValueInMap(std::map<std::string, int> &words, std::string word)
{
    if(word.empty())
    {
        return;
    }
    if(words.find(word) != words.end())
    {
        words[word]++;
    }
    else {
        words[word]=startCount;
    }
}

std::map<std::string, int> funcWordCount(std::string str)
{
    std::map<std::string, int> allWords;
    if(str.empty())
    {
        return allWords;
    }
    size_t startPosition = 0;
    size_t nextPosition = 0;
    while(startPosition <= str.size())
    {
        nextPosition = str.find(SPACE,startPosition);
        if(nextPosition == std::string::npos)
        {
            changeCountValueInMap(allWords, str.substr(startPosition));
            return allWords;
        }
        changeCountValueInMap(allWords, str.substr(startPosition,nextPosition - startPosition));
        startPosition = nextPosition + 1;
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

TEST(funcWordCount, countPlease)
{
     ASSERT_EQ(funcWordCount("olly olly in come free please please let it be in such manner olly")["please"], 2);
}

TEST(funcWordCount, countOlly)
{
     ASSERT_EQ(funcWordCount("olly olly in come free please please let it be in such manner olly")["olly"], 3);
}

TEST(funcWordCount, countIn)
{
     ASSERT_EQ(funcWordCount("olly olly in come free please please let it be in! such manner olly")["in"], 2);
}

TEST(funcWordCount, countCome)
{
     ASSERT_EQ(funcWordCount("olly olly in come free please please let it be in such manner olly")["come"], 1);
}

TEST(funcWordCount, countFree)
{
     ASSERT_EQ(funcWordCount("olly olly in come free please please let it be in such manner olly")["free"], 1);
}

TEST(funcWordCount, countLet)
{
     ASSERT_EQ(funcWordCount("olly olly in come free please please let it be in such manner olly")["let"], 1);
}

TEST(funcWordCount, withSomeSpaces_mapHas2Key)
{
     ASSERT_EQ(funcWordCount("olly olly  in").size(), 2);
}

TEST(funcWordCount, withPunctualSymbols_mapHas2Key)
{
     ASSERT_EQ(funcWordCount("olly olly,  in!").size(), 2);
}
