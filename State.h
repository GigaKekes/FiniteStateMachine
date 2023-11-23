#ifndef FSM_STATE
#define FSM_STATE

#include <string>

namespace DeeterministicFSM
{
	template <typename AssociatedObject>
	class State
	{
	public:
		State(AssociatedObject signature)
		{
			_signature = signature;
			_id = _LatestID;
			_LatestID++;
		}

		unsigned int GetID()
		{
			return _id;
		}

		AssociatedObject GetSignature()
		{
			return _signature;
		}

	private:
		AssociatedObject _signature; // Classification of this State
		unsigned int _id; // ID of this State
		static unsigned int _LatestID;
	};

	template<typename AssociatedObject>
	unsigned int DeeterministicFSM::State<AssociatedObject>::_LatestID = 0;
}

#endif // FSM_STATE

