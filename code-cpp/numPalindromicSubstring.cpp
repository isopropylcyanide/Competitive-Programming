#include <iostream>

using namespace std;

/**
 * Given a string s, return the number of palindromic substrings in it.
 */

int countSubstrings(string s) {
    // Essentially same as finding the longest palindromic substring,
    // but this time, we keep a counter
    if (s.empty()) {
        return 0;
    }
    int n = s.size(), counter = 0;
    bool dp[n + 1][n + 1];
    memset(dp, false, (n + 1) * (n + 1) * sizeof(bool));

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            int x = i;
            int y = x + j;
            if (x == y) {
                // base case
                dp[x][y] = true;
                counter += 1;
                // no need to update the bound meh..
            } else {
                if (s[x] == s[y]) {
                    // if ends are equal, check if remainder is a palindrome
                    // edge case: length 2 palindrome
                    if (x + 1 > y - 1 || dp[x + 1][y - 1]) {
                        // this is a palindrome too
                        dp[x][y] = true;
                        counter += 1;
                    }
                }
            }
        }
    }

    return counter;
}

int main() {
    std::cout << countSubstrings("abc") << std::endl;
    std::cout << countSubstrings("aaa") << std::endl;
    std::cout << countSubstrings("a") << std::endl;
    std::cout << countSubstrings("ac") << std::endl;
    std::cout << countSubstrings("racecar") << std::endl;
    std::cout << countSubstrings("aacabdkacaa") << std::endl;
    return 0;
}