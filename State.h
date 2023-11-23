#ifndef FINITESTATEMACHINE_STATE
#define FINITESTATEMACHINE_STATE

#include <string>

namespace DeeterministicFSM
{
	template <typename StateTriggerType>
	class State
	{
	public:
		State(std::string signature);
		std::string GetSignature(); // returns signature of this state

	private:
		std::string _signature; // Classification of this State
		unsigned int _id; // ID of this State
		static int _latestId; // _id + 1 of the latest State object. Zero if no State object initialized
	};
}


#endif // FINITESTATEMACHINE_STATE

