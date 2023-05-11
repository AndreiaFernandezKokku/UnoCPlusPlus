#pragma once
#include <vector>
#include "../../UnoCPlusPlus/Utilities/IInputVariables.h"

namespace UnoUnitTest
{
	class InputVariablesManagerMocked : public IInputVariables
	{
		int indexCount = 0;

	public:
		std::vector<int> IntegerInputs;
		std::string StringInput;

		InputVariablesManagerMocked(int integerInput) :
			IntegerInputs{ integerInput },
			StringInput{ "" }
		{};
		InputVariablesManagerMocked(std::vector<int> integerInputs) :
			IntegerInputs{ integerInputs },
			StringInput{ "" }
		{};


		int GetIntegerInput(std::string stringRequest, int minSize, int maxSize)
		{
			int valueToReturn = IntegerInputs[indexCount];
			indexCount++;
			if (indexCount > static_cast<int>(IntegerInputs.size()))
			{
				indexCount = 0;
			}
			return valueToReturn;
		}
		std::string GetStringInput(std::string stringRequest, int minSize, int maxSize)
		{
			return StringInput;
		}
		~InputVariablesManagerMocked() = default;
	};
}

