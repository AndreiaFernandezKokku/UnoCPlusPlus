#pragma once
#include <vector>
#include <string>
#include <memory>

using _string = std::string;
using _vectorToString = std::vector<_string>;

class RandomNameGenerator
{
private:
	_vectorToString allNames;

public:
	RandomNameGenerator();
	const std::string& CompleteRandomName();
};

