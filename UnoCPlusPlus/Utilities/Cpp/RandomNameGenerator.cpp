#include "../Header/RandomNameGenerator.h"
#include "../Header/RandomUtility.h"
#include <cassert>

RandomNameGenerator::RandomNameGenerator()
{
	allNames = { "Gotama","Telesphoros","Tangaroa","Avilius","Wodan",
		"Radhika","Albertus","Chandrashekhar","Lalita","Abhishek","Viator",
		"Fridenot","Fridwald","Devi","Vebjorn","Laurentinus","Deianira","Onouphrios",
		"Helga","Traianus" };
}

const std::string RandomNameGenerator::CompleteRandomName()
{
	assert(allNames.size() > 0,
		"Need more names on random name generator. The names do not repeat.");
	int index = RandomUtility::RandRange(0, allNames.size() - 1);
	const _string name = allNames[index];
	allNames.erase(allNames.begin() + index);
	return name;
}
