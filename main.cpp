#include <iostream>

#include "State.h"

using namespace DeeterministicFSM;

int main()
{
	State<std::string> firstState("First state");
	State<std::string> secondState("Second state");
	State<std::string> thirdState("Third state");

	std::cout << firstState.GetSignature() << " " << firstState.GetID() << std::endl;
	std::cout << secondState.GetSignature() << " " << secondState.GetID() << std::endl;
	std::cout << thirdState.GetSignature() << " " << thirdState.GetID() << std::endl;
}