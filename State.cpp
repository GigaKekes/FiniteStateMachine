#include "State.h"


DeeterministicFSM::State::State(std::string signature)
{
	_signature = signature;
	_id = _latestId;
	_latestId++;
}

std::string DeeterministicFSM::State::GetSignature()
{
	return _signature;
}

unsigned int DeeterministicFSM::State::GetID()
{
	return _id;
}

unsigned int DeeterministicFSM::State::_latestId = 0;
