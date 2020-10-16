#include "../json.h"
#include <gtest/gtest.h>

TEST(JsonTest, Parseisstream)
{
	std::map<std::string,std::string> expected;
	expected["name"]="Petyero";
	expected["hp"]="200";
	expected["dmg"]="50";
	std::ifstream input;
	input.open("Units/Petyero.json");
	std::map<std::string,std::string> output=Parser::Parse(input);
	input.close();
    EXPECT_EQ(output,expected);
}

TEST(JsonTest, ParseString)
{
    std::map<std::string, std::string> data = Parser::Parse("{    \"name\" : \"Petyero\",    \"hp\" : 200,    \"dmg\" : 50}");
    ASSERT_EQ(data["name"], "Petyero");
    ASSERT_EQ(data["hp"], "200");
    ASSERT_EQ(data["dmg"], "50");
}

TEST(JsonTest, Filetest)
{
    ASSERT_THROW(Parser::Parse("nope.json"), std::runtime_error);
    ASSERT_NO_THROW(Parser::Parse("../Unit/Petyero.json"));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}