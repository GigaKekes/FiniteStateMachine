#include <iostream>
#include <vector>

#include "State.h"
#include "TransitionFunction.h"
#include "FiniteStateAutomata.h"

using namespace DeeterministicFSM;

void StateTemplateTest();
void StringChainPatternTest();

int main(int argc, char** argv)
{
	StringChainPatternTest();

	return 0;
}


void StateTemplateTest()
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

void StringChainPatternTest()
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

	Transition<bool, char> g(thirdState, firstState, '1');
	Transition<bool, char> h(thirdState, secondState, '0');


	//Constructing FSA itself
	DeterministicFSM<bool, char> fsm({ initialState, firstState, secondState, thirdState }, { a,b,c,d,e,f,g,h }, initialState);


	//Testing
	std::vector<char> s = {  '1', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '0', '0', '1', '0' };
	
	std::vector<bool> signs = fsm.GetTriggeredChainSignatures(s);
	fsm.Restart();
	std::vector<unsigned int> ids = fsm.GetTriggeredChainIDs(s);
	fsm.Restart();
	State<bool> laststate = fsm.GetTriggeredChainState(s);
	
	std::cout << "State signatures history:\t";
	for (int i = 0; i < signs.size(); i++)
	{
		std::cout << signs[i];
	}

	std::cout << std::endl;

	std::cout << "State IDs history:\t\t";
	for (int i = 0; i < signs.size(); i++)
	{
		std::cout << ids[i];
	}

	std::cout << std::endl;

	std::cout << "Last State : ID:" << laststate.GetID() << " Value:" << laststate.GetSignature();
}