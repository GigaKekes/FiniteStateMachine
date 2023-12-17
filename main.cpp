#include <iostream>
#include <vector>
#include <string>

#include "State.h"
#include "TransitionFunction.h"
#include "FiniteStateAutomata.h"

using namespace DeeterministicFSM;

void StateTemplateTest();
void StringChainPatternTest();
void StringChainPatternTestUsingJSON();

int main(int argc, char** argv)
{
	StringChainPatternTest();

	return 0;
}


void StateTemplateTest()
{
	State firstStringState( false);
	State secondStringState(false);
	State thirdStringState(true);

	std::cout << "First String State: "  << firstStringState.GetID() << std::endl;
	std::cout << "Second String State: " << secondStringState.GetID() << std::endl;
	std::cout << "Third String State: " << thirdStringState.GetID() << std::endl;
}

void StringChainPatternTest()
{
	// Constructing FSA for finding out if a string of symbols 1 and 0 contains "101" in it 


	// 4 States. 
	// Initial. 
	// First is achieved if 1 if found. 
	// Second if 10 if found. 
	// Third if 101 is found. (We found 101 pattern)

	State initialState(false);
	State firstState(false);
	State secondState(false);
	State thirdState(true);


	// Constructiong transitions
	Transition<char> a(initialState, firstState, '1');
	Transition<char> b(initialState, initialState, '0');

	Transition<char> c(firstState, firstState, '1');
	Transition<char> d(firstState, secondState, '0');

	Transition<char> e(secondState, thirdState, '1');
	Transition<char> f(secondState, initialState, '0');

	Transition<char> g(thirdState, firstState, '1');
	Transition<char> h(thirdState, secondState, '0');


	//Constructing FSA itself
	DeterministicFSM<char> fsm({ initialState, firstState, secondState, thirdState },
		{ a,b,c,d,e,f,g,h },
		initialState);


	//Testing
	std::string parsedString = "100011001100110010111010100010";
	std::vector<char> s(parsedString.begin(), parsedString.end());
	
	std::vector<unsigned int> ids = fsm.GetTriggeredChainIDs(s);
	fsm.Restart();
	bool isTerminalStateReached = fsm.Run(s);
	
	std::cout << "Initial String:\t\t\t" << parsedString << std::endl;

	std::cout << "State IDs history:\t\t";
	for (int i = 0; i < ids.size(); i++)
	{
		std::cout << ids[i];
	}

	std::cout << std::endl;

	std::cout << "Is terminal state reached:\t" << isTerminalStateReached << (isTerminalStateReached ? "(True)" : "(False)");

}

void StringChainPatternTestUsingJSON()
{
	
}