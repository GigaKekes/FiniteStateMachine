#include "State.h"


template<typename StateTriggerType>
DeeterministicFSM::State<StateTriggerType>::State(std::string signature)
{
	_signature = signature;
	_id = _latestId;
	_latestId++;
}

{
	return _signature;
}

