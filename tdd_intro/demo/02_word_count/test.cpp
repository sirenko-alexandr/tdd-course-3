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

static std::array<char, 3> s_symbosToRemove {' ', ',', '.'};

std::string convertToLowerCase(const std::string& word)
{
    std::string lowerCaseWord = "";
    for (const auto& symbol: word)
    {
        lowerCaseWord += static_cast<char>(std::tolower(symbol));
    }

    return lowerCaseWord;
}

bool needToRemoveSymbol(const char symbol)
{
    for (const auto symbolToRemove : s_symbosToRemove)
    {
        if(symbol == symbolToRemove)
        {
            return true;
        }
    }

    return false;
}

void stripAtPostion(std::string& string, unsigned long position)
{
    while (string.size() && needToRemoveSymbol(string[position]))
    {
        string.erase(position, 1);
    }
}

void stripString(std::string& string)
{
    stripAtPostion(string, 0);
    stripAtPostion(string, string.size() - 1);
}

std::string popWord(std::string& sentence)
{
    stripString(sentence);

    auto position = sentence.find_first_of(" ");

    auto word = sentence.substr(0, position);
    sentence.erase(0, position);

    stripString(word);
    return convertToLowerCase(word);
}

std::map<std::string, int> countWords(const std::string& sentence)
{
    std::map<std::string, int> wordsMap;
    std::string oparationSentence = sentence;

    while (oparationSentence.size())
    {
        auto word = popWord(oparationSentence);
        if (wordsMap.count(word) == 0)
        {
            wordsMap[word] = 0;
        }
        wordsMap[word] += 1;
    }

    return wordsMap;
}

TEST(WordCount, SimpleWord)
{
    auto words = countWords("word");
    EXPECT_EQ(1, words["word"]);
}


TEST(WordCount, TwoWords)
{
    auto words = countWords("two words");
    EXPECT_EQ(1, words["words"]);
    EXPECT_EQ(1, words["two"]);
}

TEST(WordCount, Repeating)
{
    auto words = countWords("repeat repeat");
    EXPECT_EQ(2, words["repeat"]);
}

TEST(WordCount, BigDistance)
{
    auto words = countWords("repeat    repeat");
    EXPECT_EQ(2, words["repeat"]);
}

TEST(WordCount, BigLetter)
{
    auto words = countWords("Letter letter");
    EXPECT_EQ(2, words["letter"]);
}

TEST(WordCount, PunctuationSymbols)
{
    auto words = countWords("comma, dot.");
    EXPECT_EQ(1, words["comma"]);
    EXPECT_EQ(1, words["dot"]);
}

TEST(WordCount, TaskData)
{
    auto words = countWords("olly olly in come free please please let it be in such manner olly");
    EXPECT_EQ(3, words["olly"]);
    EXPECT_EQ(2, words["in"]);
    EXPECT_EQ(1, words["come"]);
    EXPECT_EQ(1, words["free"]);
    EXPECT_EQ(2, words["please"]);
    EXPECT_EQ(1, words["let"]);
    EXPECT_EQ(1, words["it"]);
    EXPECT_EQ(1, words["be"]);
    EXPECT_EQ(1, words["manner"]);
    EXPECT_EQ(1, words["such"]);
}
