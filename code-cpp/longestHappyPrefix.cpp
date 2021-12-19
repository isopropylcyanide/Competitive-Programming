#include <iostream>
#include <string>
#include <vector>

using namespace std;

// A string is called a happy prefix if is a non-empty prefix which is also a suffix
// (excluding itself).
// Given a string s, return the longest happy prefix of s. Return an empty string ""
// if no such prefix exists.

// Essentially this problem is the first part in "kmpPatternMatch" but only deals with
// the computation of the longest prefix/suffix array. We need to return the max amongst it

ostream &operator<<(ostream &c, vector<int> &vs) {
    for (auto v : vs) {
        c << v << " -> ";
    }
    c << endl;
    return c;
}

vector<int> computeLongestPrefixSuffixArray(string pattern) {
    // construct a longest prefix that is also a suffix at each index for the pattern
    // for [ a b c d a b c a ]
    // lps [ 0 0 0 0 1 2 3 1 ]
    vector<int> lps(pattern.size(), 0);
    int left = 0, right = 1;

    // idea is to maintain left and right window, right goes to the end, whereas left
    // is used efficiently to figure out where to begin next.
    while (right < pattern.size()) {
        if (pattern[left] == pattern[right]) {
            lps[right] = left + 1;
            left = left + 1;
            right = right + 1;
        } else {
            // adjust left until you find a match on the right,
            while (left >= 0) {
                if (pattern[left] == pattern[right]) {
                    // we have a match, it's possible, we have more
                    lps[right] = lps[left] + 1;
                    left = left + 1;
                    right = right + 1;
                    break; // we could find a match
                } else {
                    if (left == 0) {
                        // no hope of moving forward, reset left and move right
                        lps[right] = 0;
                        right = right + 1;
                        break;
                    }
                    left = lps[left - 1];
                }
            }
        }
    }
    return lps;
}

string longestPrefix(string s) {
    if (s.empty()) {
        return "";
    }
    // build efficient substring array for the pattern O(needle)
    auto lps = computeLongestPrefixSuffixArray(s);
    std::cout << "LPS: " << lps << endl;

    int lastLength = lps[s.size() - 1];
    if (lastLength == 0) {
        return "";
    }
    return s.substr(0, lastLength);
    long idxWithMaxPrefix = std::distance(lps.begin(), max_element(lps.begin(), lps.end()));
    // we found out the end, we can now get to the start using its "lps" value
    int prefixLength = lps[idxWithMaxPrefix];

    if (prefixLength == 0) { // got to guard against zero values
        return "";
    }
    return s.substr(idxWithMaxPrefix - prefixLength + 1, prefixLength);
}

int main() {
//    std::cout << longestPrefix("level") << endl;
//    std::cout << longestPrefix("ababab") << endl;
//    std::cout << longestPrefix("leetcodeleet") << endl;
//    std::cout << longestPrefix("") << endl;
//    std::cout << longestPrefix("leetcode") << endl;
//    std::cout << longestPrefix("babbb") << endl;
//    std::cout << longestPrefix("bba") << endl;
    std::cout << longestPrefix("acccbaaacccbaac") << endl;
    return 0;
}
