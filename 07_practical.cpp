#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> statePopulations;

    // Populate the map with some state populations
    statePopulations["California"] = 39512223;
    statePopulations["Texas"] = 28995881;
    statePopulations["Florida"] = 21477737;
    statePopulations["New York"] = 19453561;
    statePopulations["Illinois"] = 12671821;

    // Prompt user to input a state name
    cout << "Enter the name of a state: ";
    string inputState;
    getline(cin, inputState);

    // Search for the state in the map
    auto it = statePopulations.find(inputState);

    // Display the result
    if (it != statePopulations.end()) {
        cout << "Population of " << inputState << ": " << it->second << endl;
    } else {
        cout << "State not found in the map.\n";
    }

    return 0;
}
