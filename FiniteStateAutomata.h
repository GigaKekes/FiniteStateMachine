#ifndef FSM_FINITESTATEAUTOMATA
#define FSM_FINITESTATEAUTOMATA

#include <vector>

#include "State.h"
#include "TransitionFunction.h"

namespace DeeterministicFSM
{
    template <typename TriggerType>
    class DeterministicFSM 
    {
    public:
        DeterministicFSM(std::vector<State> states, std::vector<Transition<TriggerType>> transitions, State initialState) :
            _states(states), _transitions(transitions), _currentState(initialState), _initialState(initialState) {}

        bool triggerEvent(TriggerType value)
        {
            for (auto& transition : _transitions)
            {
                if (transition.GetFromState().GetID() == _currentState.GetID() && transition.GetTrigger() == value)
                {
                    _currentState = transition.GetToState();
                    return true;
                }
            }
            return false;
        }

        std::vector<unsigned int> GetTriggeredChainIDs(std::vector<TriggerType> triggers)
        {
            std::vector<unsigned int> chain = {};
            for (int i = 0; i < triggers.size(); i++)
            {
                if (triggerEvent(triggers[i]) == false)
                {
                    return chain;
                }
                chain.push_back(_currentState.GetID());
            }
            return chain;
        }

        bool Run(std::vector<TriggerType> triggers)
        {
            for (int i = 0; i < triggers.size(); i++)
            {
                if (triggerEvent(triggers[i]) == false)
                {
                    return false;
                }
                if (_currentState.GetTerminality())
                {
                    return true;
                }
            }
            return false;
        }
        void Restart()
        {
            _currentState = _initialState;
        }

    private:
        State _initialState;
        State _currentState;
        std::vector<State> _states;
        std::vector<Transition<TriggerType>> _transitions;
    };
}

#endif // !FSM_FINITESTATEAUTOMATA