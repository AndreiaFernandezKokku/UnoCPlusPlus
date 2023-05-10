#pragma once
#include <vector>
#include <string>
#include <memory>
#include "RandomUtility.h"

using _string = std::string;
using _vectorToString = std::vector<_string>;

class RandomNameGenerator
{
private:
	_vectorToString AllNames;
	RandomUtility& RandomUtil;

public:
	RandomNameGenerator(RandomUtility& randomUtil) : RandomUtil{ randomUtil } 
	{
		AllNames = { "Gotama","Telesphoros","Tangaroa","Avilius","Wodan",
			"Radhika","Albertus","Chandrashekhar","Lalita","Abhishek","Viator",
			"Fridenot","Fridwald","Devi","Vebjorn","Laurentinus","Deianira","Onouphrios",
			"Helga","Traianus" };
	};

	const std::string CompleteRandomName();
};

