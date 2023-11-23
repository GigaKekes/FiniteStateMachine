#include <iostream>

#include "State.h"

using namespace DeeterministicFSM;

void StateClassTemplateTest();

int main()
{
	StateClassTemplateTest();
}


void StateClassTemplateTest()
{
	State<std::string> firstStringState("AAA");
	State<std::string> secondStringState("BBB");
	State<std::string> thirdStringState("CCC");

	std::cout << "First String State: " << firstStringState.GetSignature() << " " << firstStringState.GetID() << std::endl;
	std::cout << "Second String State: " << secondStringState.GetSignature() << " " << secondStringState.GetID() << std::endl;
	std::cout << "Third String State: " << thirdStringState.GetSignature() << " " << thirdStringState.GetID() << std::endl;


	State<int> firstIntState(1);
	State<int> secondIntState(2);
	State<int> thirdIntState(3);

	std::cout << "First Int State: " << firstIntState.GetSignature() << " " << firstIntState.GetID() << std::endl;
	std::cout << "Second Int State: " << secondIntState.GetSignature() << " " << secondIntState.GetID() << std::endl;
	std::cout << "Third Int State: " << thirdIntState.GetSignature() << " " << thirdIntState.GetID() << std::endl;
}