#ifndef FSM_TRANSITIONFUNCTION
#define FSM_TRANSITIONFUNCTION

#include "State.h"

namespace DeeterministicFSM
{
    template <typename StateAssociatedObject, typename TriggerType>
    class Transition 
    {
    public:
        Transition() {}
        Transition(State<StateAssociatedObject> fromState, State<StateAssociatedObject> toState, TriggerType trigger) :
            _fromState(fromState), _toState(toState), _trigger(trigger) {}

        Transition(const Transition<StateAssociatedObject, TriggerType>& other)
        {
            this->_fromState = other._fromState;
            this->_toState = other._toState;
            this->_trigger = other._trigger;
        }

        ~Transition() {}

        Transition& operator=(const Transition& other)
        {
            if (this != &other)
            {
                _fromState = other._fromState;
                _toState = other._toState;
                _trigger = other._trigger;
            }
            return *this;
        }

        State<StateAssociatedObject> GetFromState()
        {
            return _fromState;
        }

        State<StateAssociatedObject> GetToState()
        {
            return _toState;
        }

        TriggerType GetTrigger() const
        {
            return _trigger;
        }

    private:
        State<StateAssociatedObject> _fromState;
        State<StateAssociatedObject> _toState;
        TriggerType _trigger;
    };

}

#endif // !FSM_TRANSITIONFUNCTION

