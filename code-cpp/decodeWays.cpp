#include <bits/stdc++.h>

/*
 * A message containing letters from A-Z can be encoded into numbers using the 
 * following mapping: A - 1, ... Z - 26
 * 
 * Given a non-empty string num containing only digits, return the number
 * of ways to decode it. (containing at least one number) which has the largest
 * 
 * Input: 226
 * Output: 3
 * Explanation: BBF, BZ, VF
 */

/** This function calculates the number of ways the decoding is possible
 * for the characters represented from i to the end of the string
*/
int numDecodings(string s) {
    int n = s.size();
    int dp[n + 1];
    for (int i = 0; i <= n; i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1; 

    for (int i = 2; i <= n; i++){
        int oneDigit = s[i - 1] - '0';
        int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (oneDigit >= 1){
            dp[i] += dp[i - 1]; 
        }
        if (twoDigit >= 10 && twoDigit <= 26){
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::cout << numDecodings("12") << std::endl;
    // std::cout << numDecodings("0") << std::endl;
    // std::cout << numDecodings("06") << std::endl;
    // std::cout << numDecodings("2") << std::endl;
    // std::cout << numDecodings("23") << std::endl;
    // std::cout << numDecodings("226") << std::endl;
    return 0;
}
