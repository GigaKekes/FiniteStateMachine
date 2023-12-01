# Deterministic Finite-State Machine (DFSM) in C++

This C++ program provides a simple implementation of a Deterministic Finite-State Machine (DFSM). The FSM consists of states, transitions, and the ability to transition between states.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [License](#license)
- [Contact](#contact)

## Introduction

The program defines three classes:

1. `State`: Represents a state in the FSM. Each state has a name.

2. `Transition`: Represents a transition between two states triggered by a specific event.

3. `DeterministicFSM`: Represents the Deterministic Finite-State Machine, composed of states and transitions. It provides methods to trigger events and retrieve the current state.

## Usage

To use the FSM, follow these steps:

1. Define states using the `State` class template with the desired assosiated class type.

2. Define transitions using the `Transition` class template with the appropriate class type and trigger type.

3. Create an instance of `DeterministicFSM` with the defined states, transitions, and an initial state.

4. Trigger state changes using the `Run` method to transition between states.

Example:

```cpp
#include <iostream>
#include <string>
#include <vector>

#include "FiniteStateAutomata.h"

int main() {
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
    DeterministicFSM<std::string, char> fsm({ initialState, firstState, secondState, thirdState }, { a,b,c,d,e,f,g,h }, initialState);
    
    
    //Testing
    std::string parsedString = "100011001100110010111010100010";
    std::vector<char> s(parsedString.begin(), parsedString.end());
  
    bool isTerminalStateReached = fsm.Run(s);
  
    std::cout << "Is terminal state reached:\t" << isTerminalStateReached << (isTerminalStateReached ? "(True)" : "(False)");
  
    return 0;
}
```

## License

This project is licensed under the MIT License. Feel free to modify, distribute, and use the code for personal and educational purposes.

## Contact
If you have any questions, suggestions, or feedback, please feel free to contact me
Dmitry: st119023@student.spbu.ru
