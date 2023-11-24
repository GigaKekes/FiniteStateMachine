#include <iostream>

#include "State.h"
#include "TransitionFunction.h"
#include <vector>
#include "FiniteStateAutomata.h"

using namespace DeeterministicFSM;

void StateClassTemplateTest();
void FindingStringPatternTest();

int main(int argc, char** argv)
{
	FindingStringPatternTest();

	return 0;
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

void FindingStringPatternTest()
{
	// Constructing FSA for finding out if a string of symbols 1 and 0 contains "101" in it 


	// 4 States. 
	// Initial. 
	// First is achieved if 1 if found. 
	// Second if 10 if found. 
	// Third if 101 is found. (We found 101 pattern)

	State<bool> initialState(false);
	State<bool> firstState(false);
	State<bool> secondState(false);
	State<bool> thirdState(true);


	// Constructiong transitions
	Transition<bool, char> a(initialState, firstState, '1');
	Transition<bool, char> b(initialState, initialState, '0');

	Transition<bool, char> c(firstState, firstState, '1');
	Transition<bool, char> d(firstState, secondState, '0');

	Transition<bool, char> e(secondState, thirdState, '1');
	Transition<bool, char> f(secondState, initialState, '0');

	Transition<bool, char> g(thirdState, thirdState, '1');
	Transition<bool, char> h(thirdState, thirdState, '0');


	//Constructing FSA itself
	DeterministicFSM<bool, char> fsm({initialState, firstState, secondState, thirdState }, {a,b,c,d,e,f,g,h}, initialState);


	//Testing
	fsm.triggerEvent('1');
	std::cout << "Current State: " << fsm.GetCurrentState().GetSignature() << std::endl;

	fsm.triggerEvent('0');
	std::cout << "Current State: " << fsm.GetCurrentState().GetSignature() << std::endl;

	fsm.triggerEvent('1');
	std::cout << "Current State: " << fsm.GetCurrentState().GetSignature() << std::endl;
}