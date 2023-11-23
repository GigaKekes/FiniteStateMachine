#include "State.h"


template<typename StateTriggerType>
DeeterministicFSM::State<StateTriggerType>::State(std::string signature)
{
	_signature = signature;
	_latestId++;
}

template<typename StateTriggerType>
std::string DeeterministicFSM::State<StateTriggerType>::GetSignature()
{
	return _signature;
}

template<typename StateTriggerType>
int DeeterministicFSM::State<StateTriggerType>::_latestId = 0;
