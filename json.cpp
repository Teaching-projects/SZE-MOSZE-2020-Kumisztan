#include "json.h"
#include <sstream>

std::map<std::string, std::string> Parser::Parse_string(std::string fileName)
{
   
    std::map<std::string, std::string> strg;
	std::string ln,ln1,ln2;
	std::istringstream stream(fileName);

	while (stream)
    {
		ln1 = "", ln2 = "";
		std::getline(stream, ln);
		if (ln.find('{') == std::string::npos && ln.find('}') == std::string::npos)
        {
			for (unsigned int i = 0; i < ln.find(':'); i++)
            {
				if (ln[i] != ' ' && ln[i] != '"'){ ln1 += ln[i]; }
			}
			for (unsigned int i = ln.find(':') + 1; i < ln.size(); i++)
            {
				if (ln[i] != ' ' && ln[i] != '"' && ln[i] != ','){ ln2 += ln[i]; }
			}
			strg.insert({ ln1,ln2 });
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

