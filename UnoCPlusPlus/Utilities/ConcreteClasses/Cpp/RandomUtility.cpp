#include "../Header/RandomUtility.h"


unsigned RandomUtility::GetCurrentSeed()
{
	if (!Seed.has_value())
	{
		return std::chrono::system_clock::now().time_since_epoch().count();
	}
	else
	{
		return Seed.value();
	}
}

int RandomUtility::RandRange(int lowerBound, int upperBound)
{
	std::minstd_rand0 generator(GetCurrentSeed());
	return (generator() % (upperBound - lowerBound + 1)) + lowerBound;
}
