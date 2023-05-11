#pragma once
#include <optional>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <algorithm>	// std::shuffle

class RandomUtility
{
	std::optional<unsigned> Seed;

	unsigned GetCurrentSeed();

public:
	RandomUtility(std::optional<unsigned> seed = std::nullopt)
	{
		Seed = seed;
	}

	int RandRange(int lowerBound, int upperBound);
	
	template <class T>
	void ShuffleVector(T::iterator vectorBegin,
		T::iterator vectorEnd)
	{
		std::shuffle(vectorBegin, vectorEnd, 
			std::default_random_engine(GetCurrentSeed()));
	}
};
