#include <map>
#include <tuple>

using namespace std;

class AutomataState
{
    public:
        AutomataState(map<char, AutomataState*> transitions = {})
            : transitions(transitions) {}

        tuple<bool, AutomataState*> transition(char symbol)
        {
            auto it = transitions.find(symbol);
            if (it != transitions.end()) {
                return make_tuple(it->second != nullptr, it->second);
            }
            return make_tuple(false, nullptr);
        }

    private:
        map<char, AutomataState*> transitions;
};
