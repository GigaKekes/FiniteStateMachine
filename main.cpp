#include <iostream>

#include "State.h"

using namespace DeeterministicFSM;

int main()
{
	State firstState("First state");
	State secondState("Second state");
	State thirdState("Third state");

	std::cout << firstState.GetSignature() << " " << firstState.GetID() << std::endl;
	std::cout << secondState.GetSignature() << " " << secondState.GetID() << std::endl;
	std::cout << thirdState.GetSignature() << " " << thirdState.GetID() << std::endl;
}