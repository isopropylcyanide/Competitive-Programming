#include <iostream>

using namespace std;

/**
 * Given a string s, return the longest palindromic substring in s.
 */


string longestPalindrome(string s) {
    // to see if s1...sn is valid, we check if s[s1] == s[sn] && {s2..sn-1} is a palindrome
    // we denote 0 initially, for all. if found to be a palindrome, that cell marks it as one
    // and updates the bounds. later we can get the bounds
    if (s.empty()) {
        return "";
    }
    int n = s.size(), leftBound = 0, maxLength = 1;
    bool dp[n + 1][n + 1];
    memset(dp, false, (n + 1) * (n + 1) * sizeof(bool));

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            int x = i;
            int y = x + j;
            if (x == y) {
                // base case
                dp[x][y] = true;
                // no need to update the bound meh..
            } else {
                if (s[x] == s[y]) {
                    // if ends are equal, check if remainder is a palindrome
                    // edge case: length 2 palindrome
                    if (x + 1 > y - 1 || dp[x + 1][y - 1]) {
                        // this is a palindrome too
                        dp[x][y] = true;
                        if (maxLength < (y - x + 1)) {
                            maxLength = y - x + 1;
                            leftBound = x;
                        }
                        std::cout << "Found a palindrome : " << s.substr(x, y - x + 1) << endl;
                    }

                } else {
                    // palindrome never possible if ends don't meet
                }
            }
        }
    }

    return s.substr(leftBound, maxLength);
}

int main() {
    std::cout << longestPalindrome("babad") << std::endl;
    std::cout << longestPalindrome("cbbd") << std::endl;
    std::cout << longestPalindrome("a") << std::endl;
    std::cout << longestPalindrome("ac") << std::endl;
    std::cout << longestPalindrome("racecar") << std::endl;
    std::cout << longestPalindrome("aacabdkacaa") << std::endl;
    return 0;
}