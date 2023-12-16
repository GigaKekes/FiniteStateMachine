#ifndef FSM_FINITESTATEAUTOMATA
#define FSM_FINITESTATEAUTOMATA

#include <vector>

#include "State.h"
#include "TransitionFunction.h"

namespace DeeterministicFSM
{
    template <typename StateAssociatedObject, typename TriggerType>
    class DeterministicFSM 
    {
    public:
        DeterministicFSM(std::vector<State<StateAssociatedObject>> states, std::vector<Transition<StateAssociatedObject, TriggerType>> transitions, State<StateAssociatedObject> initialState) :
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

        std::vector<StateAssociatedObject> GetTriggeredChainSignatures(std::vector<TriggerType> triggers)
        {
            std::vector<StateAssociatedObject> chain = {};
            for (int i = 0; i < triggers.size(); i++)
            {
                if (triggerEvent(triggers[i]) == false)
                {
                    return chain;
                }
                chain.push_back(_currentState.GetSignature());
            }
            return chain;
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
        State<StateAssociatedObject> _initialState;
        State<StateAssociatedObject> _currentState;
        std::vector<State<StateAssociatedObject>> _states;
        std::vector<Transition<StateAssociatedObject, TriggerType>> _transitions;
    };
}

#endif // !FSM_FINITESTATEAUTOMATA