#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string ""

string longestCommonPrefix(vector<string> &strs) {
    string prefix = "";
    int maxIdx = -1;
    int minLength = std::min_element(strs.begin(), strs.end())->size();
    int numStr = strs.size();

    if (numStr == 1) {
        return strs[0];
    }

    bool shortCircuit = false;
    for (int j = 0; j < minLength; j++) {
        // check if char is equal
        char pivot = strs[0][j];
        for (int i = 1; i < numStr; i++) {
            if (strs[i][j] != pivot) {
                shortCircuit = true;
                break;
            }
        }
        if (shortCircuit) {
            break;
        }
        maxIdx = j;
    }
    return strs[0].substr(0, maxIdx + 1);
}


int main() {
    vector<string> strs1{"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs1) << endl;

    vector<string> strs2{"dog", "racecar", "car"};
    cout << longestCommonPrefix(strs2) << endl;

    vector<string> strs3{"ab", "a"};
    cout << longestCommonPrefix(strs3) << endl;
    return 0;
}
