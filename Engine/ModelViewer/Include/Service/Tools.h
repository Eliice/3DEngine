
#pragma once
#include <functional>
#include <vector>
#include <string>
#include <unordered_map>

class Tools
{
public:
	Tools();
	~Tools();

	static std::vector<std::string> Split(std::string const& line, char delim = ' ');
	static std::vector<float> SplitFloats(std::string const& line, char delim = ' ');
	static std::vector<int> SplitInts(std::string const& line, char delim = ' ');
	static std::vector<float> StringVectorToFloatVector(std::vector<std::string>);
	static std::vector<int> StringVectorToIntVector(std::vector<std::string>);

	template<class T>
	static T* IterateMap(std::unordered_map<std::string, T*> map, int index)
	{
		if (index >= map.size())
			return nullptr;

		std::unordered_map<std::string, T*>::iterator it = map.begin();

		for (int i = 0; i < index; i++)
			++it;

		if (it != map.end())
			return it->second;

		return nullptr;
	}
};

