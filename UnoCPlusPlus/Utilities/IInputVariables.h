#pragma once
#include <string>

class IInputVariables
{
public:
	//Stopping wrong delete
	virtual ~IInputVariables() = default;

	virtual int GetIntegerInput(std::string stringRequest, int minSize, int maxSize) = 0;
	virtual std::string GetStringInput(std::string stringRequest,
		int minSize, int maxSize) = 0;
};