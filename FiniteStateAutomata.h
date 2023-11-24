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
            _states(states), _transitions(transitions), _currentState(initialState) {}

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

        State<StateAssociatedObject> GetCurrentState() 
        {
            return _currentState;
        }

    private:
        State<StateAssociatedObject> _currentState;
        std::vector<State<StateAssociatedObject>> _states;
        std::vector<Transition<StateAssociatedObject, TriggerType>> _transitions;
    };
}

#endif // !FSM_FINITESTATEAUTOMATA