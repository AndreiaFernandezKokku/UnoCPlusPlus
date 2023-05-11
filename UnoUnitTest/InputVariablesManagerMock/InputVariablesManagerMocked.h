#pragma once
#include "../../UnoCPlusPlus/Utilities/IInputVariables.h"

namespace UnoUnitTest
{
	class InputVariablesManagerMocked : public IInputVariables
	{
	public:
		int IntegerInput;
		std::string StringInput;

		InputVariablesManagerMocked(int integerInput,
			std::string stringInput) :
			IntegerInput{ integerInput },
			StringInput{ stringInput }
		{
		};
		int GetIntegerInput(std::string stringRequest, int minSize, int maxSize)
		{
			return IntegerInput;
		}
		std::string GetStringInput(std::string stringRequest, int minSize, int maxSize)
		{
			return StringInput;
		}
		~InputVariablesManagerMocked() = default;
	};
}

