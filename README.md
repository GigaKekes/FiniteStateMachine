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

### Manual method

To use the FSM, follow these steps:

1. Define states using the `State` class template with the desired assosiated class type.
 
 ```cpp
State<std::string> initialState("0", false); // Initial. 
State<std::string> firstState("1", false);   // First is achieved if 1 if found. 
State<std::string> secondState("10", false); // Second if 10 if found. 
State<std::string> thirdState("101", true);  // Third if 101 is found. (We found 101 pattern)
```

2. Define transitions using the `Transition` class template with the appropriate class type and trigger type.
```cpp
// Constructiong transitions
Transition<std::string, char> a(initialState, firstState, '1');
Transition<std::string, char> b(initialState, initialState, '0');

Transition<std::string, char> c(firstState, firstState, '1');
Transition<std::string, char> d(firstState, secondState, '0');

Transition<std::string, char> e(secondState, thirdState, '1');
Transition<std::string, char> f(secondState, initialState, '0');

Transition<std::string, char> g(thirdState, firstState, '1');
Transition<std::string, char> h(thirdState, secondState, '0');
```
3. Create an instance of `DeterministicFSM` with the defined states, transitions, and an initial state.
```cpp
//Constructing FSA itself
DeterministicFSM<std::string, char> fsm({ initialState, firstState, secondState, thirdState }, { a,b,c,d,e,f,g,h }, initialState);
```
4. Trigger state changes using the `Run` method to transition between states.

Example:

```cpp
std::string parsedString = "100011001100110010111010100010";
std::vector<char> s(parsedString.begin(), parsedString.end());

bool isTerminalStateReached = fsm.Run(s);
```
### JSON parsing method

To use the FSM, follow these steps:

1. Make a JSON file of structure:
#### States:
The "States" key contains an array of boolean values respectful to IDs of states starting with 0.
Each boolean value corresponds to a state in the finite state machine by its ID.
In this example, there are four states represented by the boolean values [false, false, false, true].
The states are indexed starting from 0, and the state with true corresponds to State 3.

#### Transitions:
The "Transitions" key contains an array of objects, each representing a transition in the finite state machine.

Each transition object has the following properties:

1. from: The ID of a state from which the transition originates.
2. to: The ID of a state to which the transition leads.
3. trigger: The trigger or input that causes the transition.

Example:

```json
{
  "States": [
    false,
    false,
    false, 
    true
  ],

  "Transitions": [
    {
      "from": 0,
      "to": 1,
      "trigger": "1"
    },
    {
      "from": 0,
      "to": 0,
      "trigger": "0"
    },
    {
      "from": 1,
      "to": 1,
      "trigger": "1"
    },
    {
      "from": 1,
      "to": 2,
      "trigger": "0"
    },
    {
      "from": 2,
      "to": 0,
      "trigger": "0"
    },
    {
      "from": 2,
      "to": 3,
      "trigger": "1"
    },
    {
      "from": 3,
      "to": 2,
      "trigger": "0"
    },
    {
      "from": 3,
      "to": 1,
      "trigger": "1"
    }
  ]
}
```
2. Create an instance of `DeterministicFSM` with the path to your JSON file and a type of this resourse file (currently we only have JSON).

```cpp
//Path for our Json File
std::string path = "AutomataSetup.json";

//Constructing FSA
DeterministicFSM<std::string> fsm(path, FSAResourceFileType::JSONFile);
```
3. Trigger state changes using the `Run` method to transition between states.

```cpp
std::string parsedString = "100011001100110010111010100010";
std::vector<std::string> s = splitString(parsedString);

bool isTerminalStateReached = fsm.Run(s);
std::cout << "Is terminal state reached:\t" << isTerminalStateReached << (isTerminalStateReached ? "(True)" : "(False)");
```


## License

This project is licensed under the MIT License. Feel free to modify, distribute, and use the code for personal and educational purposes.

## Contact
If you have any questions, suggestions, or feedback, please feel free to contact me
Dmitry: st119023@student.spbu.ru
