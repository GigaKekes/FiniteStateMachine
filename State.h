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

	private:
		std::string _signature; // Classification of this State
		unsigned int _id; // ID of this State
	};
}


#endif // FINITESTATEMACHINE_STATE

