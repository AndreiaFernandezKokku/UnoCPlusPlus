#include "../Header/InputVariablesManager.h"
#include <iostream>

int InputVariablesManager::GetIntegerInput(std::string stringRequest, int minValue, int maxValue)
{
	bool valid = false;

	while (!valid)
	{
		printf("%s \n", stringRequest.c_str());
		std::string tempString;

		std::getline(std::cin, tempString);
		try
		{
			int result = stoi(tempString);
			valid = IsInsideBoundaries(result, minValue, maxValue);
			if (valid) return result;
		} catch (std::invalid_argument)
		{
			printf("Invalid value \n");
			valid = false;
		}
	}
	return 0;
}

std::string InputVariablesManager::GetStringInput(std::string stringRequest, 
	int minSize, int maxSize)
{
	bool valid = false;

	while (!valid)
	{
		printf("%s \n", stringRequest.c_str());
		std::string tempString;

		std::getline(std::cin, tempString);
		bool isSmallerThanMinSize = tempString.size() < minSize;
		bool isBiggerThanMaxSize = tempString.size() > maxSize;

		if (isSmallerThanMinSize || isBiggerThanMaxSize)
		{
			valid = false;
			if (isSmallerThanMinSize)
			{
				printf("Name needs to be longer \n");
			}
			else
			{
				printf("Name is too long \n");
			}
		}
		else
		{
			valid = true;
			return tempString;
		}
	}
}

bool InputVariablesManager::IsValid(int input)
{
	if (!input)
	{
		printf("Invalid value \n");
		return false;
	}
	return true;
}

bool InputVariablesManager::IsInsideBoundaries(int input, int minValue, int maxValue)
{
	if (input < minValue)
	{
		printf("Input below limit \n");
		return false;
	}
	if (input > maxValue)
	{
		printf("Input above limit \n");
		return false;
	}
	return true;
}

