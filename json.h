#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
class Parser
{
public:
        static std::map<std::string, std::string> Parse(std::string fileString);
        static std::map<std::string, std::string> Parse(std::ifstream& fileStream);  
        static std::map<std::string, std::string> Parse(const char *fileName); 
};

#endif