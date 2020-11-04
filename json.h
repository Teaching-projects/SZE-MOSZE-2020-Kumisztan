#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
class Parser
{
public:
        static std::map<std::string, std::string> Parse_string(const std::string& fileString);
        static std::map<std::string, std::string> Parse_stream(std::ifstream& fileStream);       
        static std::map<std::string, std::string> Parse_file(const std::string&);
};

#endif