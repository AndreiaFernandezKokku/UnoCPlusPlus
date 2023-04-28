#include "../Header/RandomUtility.h"


int RandomUtility::RandRange(int lowerBound, int upperBound)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::minstd_rand0 generator(seed);
	return (generator() % (upperBound - lowerBound + 1)) + lowerBound;
}
