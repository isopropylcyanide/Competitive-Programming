#include <bits/stdc++.h>

string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    string ans = "";
    int minWindowLength = INT_MAX;
    int bestWindowLeft = -1;
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == t[j]) {
            j += 1;
            if (j >= m) {
                //found a window, we just need to minimize this
                int end = i;
                j -= 1;
                while (j >= 0) {
                    if (s[i] == t[j]) {
                        //
                        j -= 1;
                    }
                    i -= 1;
                }
                //now from i to end, we have a match
                //check if smallest..not lteq because first
                i += 1;
                j = 0;
                if (minWindowLength > (end - i + 1)) {
                    minWindowLength = end - i + 1;
                    bestWindowLeft = i;
                }
            }
        }
    }
    return minWindowLength == INT_MAX ? "" : s.substr(bestWindowLeft, minWindowLength);
}

int main() {
    // string s = "ADOBECODEBANC";
    // string t = "ABC";
    string s = "bdgdddddddddddddddbde";
    string t = "bde";
    std::cout << minWindow(s, t) << endl;
    return 0;
}