#include <vector>
#include <string>
#include "automata-base.hpp"
#include "automata-state.hpp"

using namespace std;


class DeterministicFiniteAutomata : public AutomataBase
{
    public:
        DeterministicFiniteAutomata(vector<AutomataState> states, const vector<char>& inputSymbols, int initialIndex, const vector<int>& finalIndexes)
            : states(states), inputs(inputSymbols), initialIndex(initialIndex), finalIndexes(finalIndexes) {}

        bool isAccepted(const string& input)
        {
            currentState = states[initialIndex];

            for (char symbol : input) {
                if (&currentState == nullptr) {
                    return false;
                }

                tuple<bool, AutomataState*> transitionTuple = currentState.transition(symbol);
                if (!get<0>(transitionTuple)) {
                    return false;
                }
                currentState = *get<1>(transitionTuple);
            }
            return find(finalIndexes.begin(), finalIndexes.end(), &currentState - &states[0]) != finalIndexes.end();
        }

    private:
        const int initialIndex;
        const vector<int> finalIndexes;
        const vector<AutomataState> states;
        const vector<char> inputs;

        AutomataState currentState;
};
