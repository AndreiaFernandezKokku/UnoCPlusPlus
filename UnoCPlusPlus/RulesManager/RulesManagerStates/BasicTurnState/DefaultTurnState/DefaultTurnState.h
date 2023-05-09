#pragma once
#include "../BasicTurnState.h"
/// <summary>
/// Class added just to allow the template (SelectStateClassIndex) 
/// functionality inside the RulesManager class, otherwise every 
/// class would be the basic turn state and we would not be able to
/// select this state.
/// </summary>
class DefaultTurnState : public BasicTurnState
{
public:
	//Stopping wrong delete
	~DefaultTurnState() = default;
};

