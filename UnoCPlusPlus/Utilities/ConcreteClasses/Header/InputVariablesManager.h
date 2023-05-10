#pragma once
#include "../../IInputVariables.h"
#include <string>

class InputVariablesManager : public IInputVariables
{
public:
	int GetIntegerInput(std::string stringRequest, int minSize, int maxSize) override;
	std::string GetStringInput(std::string stringRequest, 
		int minSize, int maxSize) override;

	~InputVariablesManager() = default;

private:
	bool IsValid(int input);
	bool IsInsideBoundaries(int input, int minValue, int maxValue);
};

