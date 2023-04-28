#pragma once
#include <string>

class InputVariablesManager
{
public:
	int GetIntegerInput(std::string stringRequest, int minSize, int maxSize);
	std::string GetStringInput(std::string stringRequest, 
		int minSize, int maxSize);

private:
	bool IsValid(int input);
	bool IsInsideBoundaries(int input, int minValue, int maxValue);
};

