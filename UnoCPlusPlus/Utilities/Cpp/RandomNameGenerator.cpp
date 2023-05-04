#include "../Header/RandomNameGenerator.h"
#include "../Header/RandomUtility.h"

RandomNameGenerator::RandomNameGenerator()
{
	allNames = { "Gotama","Telesphoros","Tangaroa","Avilius","Wodan",
		"Radhika","Albertus","Chandrashekhar","Lalita","Abhishek","Viator",
		"Fridenot","Fridwald","Devi","Vebjorn","Laurentinus","Deianira","Onouphrios",
		"Helga","Traianus" };
}

const std::string& RandomNameGenerator::CompleteRandomName()
{
	//todo remove used name
	int index = RandomUtility::RandRange(0, allNames.size() - 1);
	return allNames[index];
}
