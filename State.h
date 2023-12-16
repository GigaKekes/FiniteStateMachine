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
		State(StateAssociatedObject signature, bool isTerminal) :
			_signature(signature), _id(_LatestID), _isTerminal(isTerminal)
		{
			_LatestID++;
		}

		State(const State<StateAssociatedObject>& other)
		{
				this->_signature = other._signature;
				this->_id = other._id;
				this->_isTerminal = other._isTerminal;
		}
		~State() {}

		State& operator=(const State& other)
		{
			if (this != &other)
			{
				this->_signature = other._signature;
				this->_id = other._id;
				this->_isTerminal = other._isTerminal;
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

		bool GetTerminality() const
		{
			return _isTerminal;
		}

	private:
		StateAssociatedObject _signature; // Classifies unique data of this State
		unsigned int _id; // Represents ID of this State
		bool _isTerminal; // Determines if class is in a set of final states
		static unsigned int _LatestID;
	};

	template<typename StateAssociatedObject>
	unsigned int DeeterministicFSM::State<StateAssociatedObject>::_LatestID = 0;
}

#endif // FSM_STATE

