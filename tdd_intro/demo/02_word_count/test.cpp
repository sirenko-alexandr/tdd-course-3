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

std::map<std::string, int> countWords(const std::string& sentence)
{
    auto position = sentence.find_first_of(" ");
    if (position == std::string::npos)
    {
        return std::map<std::string, int>{std::make_pair(sentence, 1)};
    }

    auto firstWord = sentence.substr(0, position);
    auto secondWord = sentence.substr(position + 1, sentence.size() - position - 1);

    return std::map<std::string, int>{std::make_pair(firstWord, 1),
                                      std::make_pair(secondWord, 1)};
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
