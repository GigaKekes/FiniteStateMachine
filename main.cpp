#include <iostream>
#include <vector>
#include <string>

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
	State<std::string> firstStringState("AAA", false);
	State<std::string> secondStringState("BBB", false);
	State<std::string> thirdStringState("CCC", true);

	std::cout << "First String State: " << firstStringState.GetSignature() << " " << firstStringState.GetID() << std::endl;
	std::cout << "Second String State: " << secondStringState.GetSignature() << " " << secondStringState.GetID() << std::endl;
	std::cout << "Third String State: " << thirdStringState.GetSignature() << " " << thirdStringState.GetID() << std::endl;


	State<int> firstIntState(1, false);
	State<int> secondIntState(2, false);
	State<int> thirdIntState(3, true);

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

	State<std::string> initialState("0", false);
	State<std::string> firstState("1", false);
	State<std::string> secondState("10", false);
	State<std::string> thirdState("101", true);


	// Constructiong transitions
	Transition<std::string, char> a(initialState, firstState, '1');
	Transition<std::string, char> b(initialState, initialState, '0');

	Transition<std::string, char> c(firstState, firstState, '1');
	Transition<std::string, char> d(firstState, secondState, '0');

	Transition<std::string, char> e(secondState, thirdState, '1');
	Transition<std::string, char> f(secondState, initialState, '0');

	Transition<std::string, char> g(thirdState, firstState, '1');
	Transition<std::string, char> h(thirdState, secondState, '0');


	//Constructing FSA itself
	DeterministicFSM<std::string, char> fsm({ initialState, firstState, secondState, thirdState },
		{ a,b,c,d,e,f,g,h },
		initialState);


	//Testing
	std::string parsedString = "100011001100110010111010100010";
	std::vector<char> s(parsedString.begin(), parsedString.end());
	
	std::vector<std::string> signs = fsm.GetTriggeredChainSignatures(s);
	fsm.Restart();
	std::vector<unsigned int> ids = fsm.GetTriggeredChainIDs(s);
	fsm.Restart();
	bool isTerminalStateReached = fsm.Run(s);
	
	std::cout << "Initial String:\t\t\t" << parsedString << std::endl;
	std::cout << "State signatures history:\t";
	for (int i = 0; i < signs.size(); i++)
	{
		std::cout << signs[i] << ' ';
	}

	std::cout << std::endl;

	std::cout << "State IDs history:\t\t";
	for (int i = 0; i < signs.size(); i++)
	{
		std::cout << ids[i];
	}

	std::cout << std::endl;

	std::cout << "Is terminal state reached:\t" << isTerminalStateReached << (isTerminalStateReached ? "(True)" : "(False)");

}