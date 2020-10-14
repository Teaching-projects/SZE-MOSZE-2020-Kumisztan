#ifndef JSON_H
#define JSON_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>
class Parser
{
public:
        static std::map<std::string, std::string> Parse_string(const std::string& filename);
        static std::map<std::string, std::string> Parse_stream(std::istream& filename);   
};

#endif