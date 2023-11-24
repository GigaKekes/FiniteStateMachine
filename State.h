#ifndef FSM_STATE
#define FSM_STATE

#include <string>

namespace DeeterministicFSM
{
	template <typename StateAssociatedObject>
	class State
	{
	public:
		State() {}
		State(StateAssociatedObject signature) :
			_signature(signature), _id(_LatestID)
		{
			_LatestID++;
		}

		State(const State<StateAssociatedObject>& other)
		{
				this->_signature = other._signature;
				this->_id = other._id;
		}
		~State() {}

		State& operator=(const State& other)
		{
			if (this != &other)
			{
				_signature = other._signature;
				_id = other._id;
			}
			return *this;
		}

		unsigned int GetID() const
		{
			return _id;
		}

		StateAssociatedObject GetSignature()  const
		{
			return _signature;
		}

	private:
		StateAssociatedObject _signature; // Classification of this State
		unsigned int _id; // ID of this State
		static unsigned int _LatestID;
	};

	template<typename StateAssociatedObject>
	unsigned int DeeterministicFSM::State<StateAssociatedObject>::_LatestID = 0;
}

#endif // FSM_STATE

