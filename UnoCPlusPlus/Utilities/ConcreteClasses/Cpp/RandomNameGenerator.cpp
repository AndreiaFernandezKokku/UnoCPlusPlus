#include "../Header/RandomNameGenerator.h"
#include <cassert>

_stringVector RandomNameGenerator::GetAllNames()
{
	return AllNames;
}

const std::string RandomNameGenerator::CompleteRandomName()
{
	assert(AllNames.size() > 0,
		"Need more names on random name generator. The names do not repeat.");
	int index = RandomUtil.RandRange(0, AllNames.size() - 1);
	const _string name = AllNames[index];
	AllNames.erase(AllNames.begin() + index);
	return name;
}
