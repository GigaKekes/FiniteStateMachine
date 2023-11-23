#ifndef FINITESTATEMACHINE_STATE
#define FINITESTATEMACHINE_STATE

#include <string>

namespace DeeterministicFSM
{
	template <typename AssociatedObject>
	class State
	{
	public:
		State(AssociatedObject signature);

		unsigned int GetID();
		AssociatedObject GetSignature();

	private:
		AssociatedObject _signature; // Classification of this State
		unsigned int _id; // ID of this State
		static unsigned int _LatestID;
	};
	template<typename AssociatedObject>
	DeeterministicFSM::State<AssociatedObject>::State(AssociatedObject signature)
	{
		_signature = signature;
		_id = _LatestID;
		_LatestID++;
	}

	template<typename AssociatedObject>
	unsigned int DeeterministicFSM::State<AssociatedObject>::GetID()
	{
		return _id;
	}

	template<typename AssociatedObject>
	AssociatedObject DeeterministicFSM::State<AssociatedObject>::GetSignature()
	{
		return _signature;
	}

	template<typename AssociatedObject>
	unsigned int DeeterministicFSM::State<AssociatedObject>::_LatestID = 0;
}

#include "State.cpp"

#endif // FINITESTATEMACHINE_STATE

