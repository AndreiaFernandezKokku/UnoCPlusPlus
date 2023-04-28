#pragma once
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <algorithm>	// std::shuffle

class RandomUtility
{
public:
	static int RandRange(int lowerBound, int upperBound);
	
	template <class T>
	static void ShuffleVector(T::iterator vectorBegin,
		T::iterator vectorEnd)
	{
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(vectorBegin, vectorEnd, std::default_random_engine(seed));
	}
};
