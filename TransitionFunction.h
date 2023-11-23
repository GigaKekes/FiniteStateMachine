#ifndef FSM_TRANSITIONFUNCTION
#define FSM_TRANSITIONFUNCTION

#include "State.h"

namespace DeeterministicFSM
{
    template <typename AssociatedObject>
    class Transition 
    {
    public:
        Transition(State<AssociatedObject> fromState, State<AssociatedObject> toState, AssociatedObject trigger)
        {
            _fromState = fromState;
            _toState = toState;
            _trigger = trigger
        }

        State<AssociatedObject> getFromState() const 
        {
            return fromState;
        }

        State<AssociatedObject> getToState() const 
        {
            return toState;
        }

        AssociatedObject getTrigger() const 
        {
            return trigger;
        }

    private:
        State<AssociatedObject> _fromState;
        State<AssociatedObject> _toState;
        AssociatedObject _trigger;
    };

}

#endif // !FSM_TRANSITIONFUNCTION

