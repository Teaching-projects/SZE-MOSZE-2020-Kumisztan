#include "../json.h"
#include <gtest/gtest.h>

TEST(JsonTest, Parseisstream)
{
	std::map<std::string,std::string> expected;

	expected["name"]="PETYERO";
	expected["hp"]="200";
	expected["dmg"]="50";

	std::ifstream input;

	input.open("../Units/Petyero.json");
	std::map<std::string,std::string> output=Parser::Parse_stream(input);
	input.close();

    EXPECT_EQ(output,expected);
}

TEST(JsonTest, ParseString)
{
    std::map<std::string,std::string> expected;

	expected["name"]="PETYERO";
	expected["hp"]="200";
	expected["dmg"]="50";

	std::string input="{\n \"name\" : \"PETYERO\",\n \"hp\" : 200,\n \"dmg\": 50 \n}";
	std::map<std::string,std::string> output=Parser::Parse_string(input);

    EXPECT_EQ(output,expected);
}

TEST(JsonTest, ParseFile)
{
    std::map<std::string,std::string> expected;

	expected["name"]="PETYERO";
	expected["hp"]="200";
	expected["dmg"]="50";

	std::map<std::string,std::string> output=Parser::Parse_file("../Units/Petyero.json");
    
    EXPECT_EQ(output,expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}