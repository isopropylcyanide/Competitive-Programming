#include <bits/stdc++.h>

void preprocess(string &s, map<char, vector<int>> &charCountMap, map<char, int> &validChars) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        //for all keys
        for (auto entry : validChars) {
            if (charCountMap.find(entry.first) == charCountMap.end()) {
                //init
                charCountMap[entry.first] = vector<int>(n, 0);
            }
            if (entry.first == s[i]) {
                //do something
                charCountMap[entry.first][i] = i == 0 ? 1 : charCountMap[entry.first][i - 1] + 1;
            } else {
                charCountMap[entry.first][i] = i == 0 ? 0 : charCountMap[entry.first][i - 1];
            }
        }
    }
}

bool inWindow(int l, int r, map<char, vector<int>> &charCountMap, map<char, int> &validCharExpectedFreq) {
    //all chars should have count in range
    for (auto entry : validCharExpectedFreq) {
        char alphabet = entry.first;
        int countInWindow = l == 0 ? charCountMap[alphabet][r] : charCountMap[alphabet][r] - charCountMap[alphabet][l - 1];
        if (countInWindow < entry.second) {
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) {
    int n = s.size();
    map<char, int> validCharExpectedFreq;
    if (n < t.size()) {
        return "";
    }

    for (char s : t) {
        // validChars.insert(s);
        if (validCharExpectedFreq.find(s) == validCharExpectedFreq.end()) {
            validCharExpectedFreq[s] = 0;
        }
        validCharExpectedFreq[s] += 1;
    }
    map<char, vector<int>> charCountMap;
    preprocess(s, charCountMap, validCharExpectedFreq);

    int minWindowSize = INT_MAX;
    int left = -1;
    int right = -1;
    //so the best window would be of size t: duh..so lets start with it
    //we'll move the window according to the characters..
    //if at each [l, r], the window is minimum, we store the l and rth index
    int l = 0;
    int r = t.size() - 1;
    while (l <= r && r < n) {
        std::cout << "**************************" << endl;
        std::cout << "Checking window [" << l << ":" << r << "] : " << s.substr(l, r - l + 1) << endl;
        bool valid = inWindow(l, r, charCountMap, validCharExpectedFreq);
        if (valid) {
            std::cout << "Valid window\n";
            if (minWindowSize > (r - l + 1)) {
                //unique..set the pointers
                std::cout << "Smallest window so far\n";
                minWindowSize = r - l + 1;
                left = l;
                right = r;
                if (minWindowSize == t.size()) {
                    //nothing beats this
                    return s.substr(left, right - left + 1);
                }
            }
            //try contracting the window now
            l += 1;
        } else {
            r += 1;
        }
        //check if window l to r works..
        //need a function to see if it works
        //if exactly equal, then we move l & r both
        //if chars are less, then we move r..
        //chars cannot be more than r, duh.
    }
    //since its given that window exists, we'll have non zero values for l - r
    //output the string[l: r]
    if (left == -1 && right == -1) {
        return "";
    }
    return s.substr(left, right - left + 1);
}

int main() {
    // string s = "ADOBECODEBANC";
    // string t = "ABC";
    string s = "a";
    string t = "aa";
    std::cout << minWindow(s, t) << endl;
    return 0;
}