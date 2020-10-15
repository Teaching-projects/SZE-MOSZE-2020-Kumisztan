#include "json.h"

std::map<std::string, std::string> Parser::Parse(std::string fileName)
{
    std::ifstream fstream("Units/" + fileName);
    return Parser::Parse(fstream);
}

std::map<std::string, std::string> Parser::Parse(const char *fileName)
{
    std::string fName(fileName);
    std::ifstream file("Units/" + fName);

    return Parser::Parse(file);
}

std::map<std::string, std::string> Parser::Parse(std::ifstream &fileStream)
{
    std::map<std::string, std::string> myMap;
    char c;
    while (fileStream.get(c))
    {
        if (c == '\"')
        {
            std::string key = "";
            for (fileStream.get(c); c != '\"'; fileStream.get(c))
                key += c;

            for (fileStream.get(c); c == ':' || c == ' ' || c == '\"'; fileStream.get(c)) // skip until val starts
                ;

            std::string val = "";
            for (; c != '\"' && c != '\n' && c != ','; fileStream.get(c))
                val += c;

            myMap[key] = val;
        }
    }

    return myMap;
}

