#include <sstream>
#include "Service\Tools.h"



Tools::Tools()
{
}


Tools::~Tools()
{
}

std::vector<std::string> Tools::Split(std::string const& line, char delim)
{
	std::stringstream linestream(line);

	std::vector<std::string> splittedStr;

	std::string token;
	while (std::getline(linestream, token, delim))
	{
		if (!token.empty())
			splittedStr.push_back(token);

	}

	return splittedStr;
}

std::vector<float> Tools::SplitFloats(std::string const& line, char delim)
{
	return Tools::StringVectorToFloatVector(Tools::Split(line, delim));
}

std::vector<int> Tools::SplitInts(std::string const& line, char delim)
{
	return Tools::StringVectorToIntVector(Tools::Split(line, delim));
}

std::vector<float> Tools::StringVectorToFloatVector(std::vector<std::string> strings)
{
	std::vector<float> results;
	int index = 0;
	size_t size = strings.size();
	for(index; index < size; ++ index)
	{
		std::string val = strings[index];
		float floatVal = 0.f;

		try
		{
			floatVal = std::stof(val);
		}
		catch (std::invalid_argument){}

		results.push_back(floatVal);
	}
	
	return results;
}

std::vector<int> Tools::StringVectorToIntVector(std::vector<std::string> strings)
{
	std::vector<int> results;
	int index = 0; 
	size_t size = strings.size();
	for(index ; index < size ; ++ index)
	{
		std::string val = strings[index];
		int intVal = 0;

		try
		{
			intVal = std::stoi(val);
		}
		catch (std::invalid_argument) {}

		results.push_back(intVal);
	}

	return results;
}