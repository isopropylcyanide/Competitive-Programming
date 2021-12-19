#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Return the index of the first occurrence of needle in haystack, or -1 if needle is
// not part of haystack.

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

int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
        return 0;
    }
    // build efficient substring array for the pattern O(needle)
    auto lps = computeLongestPrefixSuffixArray(needle);
    std::cout << "LPS: " << lps << endl;
    // use the substring array to search the haystack in O(haystackpi)

    int n = haystack.size(), m = needle.size();
    int i = 0, j = 0; // pointers for haystack and needle respectively
    int possible_start = 0;

    while (i < n && j < m) {
        if (haystack[i] == needle[j]) {
            // great, move forward
            i = i + 1;
            j = j + 1;
        } else {
            if (j == 0) {
                // if we are already at the leftmost edge of pattern, we need to expand haystack
                i = i + 1;
                possible_start = i;
            } else {
                // nope, but this time, set j to the right length instead of 0
                // this is because we don't want to look back in the haystack
                j = lps[j - 1];
                // for tracking, note i's position as i - j' is the potential string start
                possible_start = i - j;
            }
        }
        if (j == m) {
            // we found the needle in the haystack from its current pointer - m
            std::cout << "We found the needle " << haystack.substr(possible_start, m) << " starting at "
                      << possible_start << endl;
            // start of the needle must be located at i - m;
            return possible_start;
        }
    }

    std::cout << "No match for " << needle << endl;
    return -1;
}

int main() {
//    int i = strStr("abcxabcdabxabcdabcdabcymia", "abcdabcy");
//    int i = strStr("abcxabcdabxabcdabcdabcy", "aabaabaaa");
//    int i = strStr("abxabcabcaby", "abcaby");
    int i = strStr("xxxxxxxxxxabababcxxxx", "abababc");
    cout << "\nMatch is " << i << endl;
    return 0;
}
