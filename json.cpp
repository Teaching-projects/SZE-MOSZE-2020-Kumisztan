#include "json.h"
#include <sstream>

/*
std::map<std::string, std::string> Parser::Parse_string(std::string input)
{
   
    std::map<std::string, std::string> strg;
	std::string line,line1,line2;
	std::istringstream stream(input);

	while (stream)
    {
		line1 = "", line2 = "";
		std::getline(stream, line);
		if (line.find('{') == std::string::npos && line.find('}') == std::string::npos)
        {
			for (unsigned int i = 0; i < line.find(':'); i++)
            {
				if (line[i] != ' ' && line[i] != '"'){ line1 += line[i]; }
			}
			for (unsigned int i = line.find(':') + 1; i < line.size(); i++)
            {
				if (line[i] != ' ' && line[i] != '"' && line[i] != ','){ line2 += line[i]; }
			}
			strg.insert({ line1,line2 });
		}
	}
	return strg;
} */

std::map<std::string, std::string> Parser::Parse_string(const std::string& input)
{
	
	std::map<std::string, std::string> strg;
	std::string line, line1, line2;
	unsigned int i = 0;
	std::istringstream stream(input);
	while (stream) {
		line1 = "", line2 = "", i = 0;
		std::getline(stream, line);
		if (line.find('{') == std::string::npos && line.find('}') == std::string::npos) {
			if (std::isspace(static_cast<unsigned char>(line[i])) || line[i] == '\"' || line[i] == ':' || line[i] == ',') {
				i++;
			}

			if (!std::isspace(static_cast<unsigned char>(line[i])) && line[i] != '\"' && line[i] != ':' && line[i] != ',') {

				line1 += line[i];
				i++;
			}

			for (unsigned int j = i + 1; j < line.size(); j++) {

				if (!std::isspace(static_cast<unsigned char>(line[j])) && line[j] != '\"' && line[j] != ':' && line[i] != ',') {
					line2 += line[j];
				}

			}
			strg.insert({ line1,line2 });
		}					
	}
	return strg;
}



std::map<std::string, std::string> Parser::Parse_file(const std::string& fileName)
{
    std::map<std::string, std::string> fName;
	std::ifstream file;

	file.open(fileName);
	fName = Parser::Parse_stream(file);
	file.close();

	return fName;
}

std::map<std::string, std::string> Parser::Parse_stream(std::ifstream &fileStream)
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

            for (fileStream.get(c); c == ':' || c == ' ' || c == '\"'; fileStream.get(c))
                ;

            std::string val = "";
            for (; c != '\"' && c != '\n' && c != ','; fileStream.get(c))
                val += c;

            myMap[key] = val;
        }
    }

    return myMap;
}

