#include <iostream>
#include <map>
#include <stack>

// Given a string s, find the length of the longest substring without repeating characters.
template<typename T>
std::ostream &operator<<(std::ostream &c, const std::stack<T> &vs) {
    std::stack<int> copy = vs;
    while (!copy.empty()) {
        c << copy.top() << " -> ";
        copy.pop();
    }
    return c;
}

template<typename U>
std::ostream &operator<<(std::ostream &c, const std::map<char, U> &map) {
    for (auto &[k, v] : map) {
        c << "Map[" << k << "]: " << v << std::endl;
    }
    return c;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

std::map<char, std::stack<int>> getCharsOnRight(const std::string s) {
    std::map<char, std::stack<int>> charRightMost;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (charRightMost.find(s[i]) == charRightMost.end()) {
            charRightMost[s[i]] = std::stack<int>();
        }
        charRightMost[s[i]].push(i);
    }
    return charRightMost;
}

int lengthOfLongestSubstring(std::string s) {
    int n = s.size();
    int maxWindowSoFar = 0, l = 0, r = 0;
    std::map<char, int> charCounts;

    while (r < n) {
        charCounts[s[r]] = charCounts[s[r]] + 1;
        while (charCounts[s[r]] > 1) {
            charCounts[s[l]] = charCounts[s[l]] - 1;
            l = l + 1;
        }
        maxWindowSoFar = max(maxWindowSoFar, r - l + 1);
        r = r + 1;
    }
    return maxWindowSoFar;
}

int lengthOfLongestSubstringStack(std::string s) {
    //prepare a stack of values for each character from right to left
    int n = s.size();
    std::map<char, std::stack<int>> charRightMost = getCharsOnRight(s);

    int maxWindowSoFar = 0, l = 0, r = n - 1;
    int currentWindowRight = n - 1;
    int currentWindowLeft = 0;
    while (l <= r) {
        std::cout << "Checking for " << l << " : " << s[l] << " and r : " << r << " maxWindow: " << maxWindowSoFar
                  << " curWindow << [" << currentWindowLeft << "-" << currentWindowRight << "] " << std::endl;

        if (l >= currentWindowRight) {
            //previous window ends here and a new window starts
            maxWindowSoFar = max(maxWindowSoFar, currentWindowRight - currentWindowLeft + 1);
            currentWindowLeft = l;
            // we don't know the right window yet but lets keep it to the max
            currentWindowRight = n - 1;
        }
        std::stack<int> &stack = charRightMost[s[l]];
        if (stack.empty()) {
            // there has to be at least one element but we would have popped it
            // window is basically until max of either the current window
            currentWindowRight = min(currentWindowRight, n - 1);

        } else {
            // check if current element is not the top one
            if (stack.top() == l) {
                // we need to get rid of it and repeat
                stack.pop();
                continue;

            } else {
                // there exists a valid bound, restrict window to that
                // there is a potential of l to r, not beyond that for sure
                // the ideal window would be >= l and <= r
                // currentWindowLeft = l;

                // note if you were a part of current window, then update it
                if (stack.top() > currentWindowRight) {
                    // we are good and do not need to update window right because we
                    // are already restricted we also maintain the same window left pointer
                } else {
                    // we have further restricted the range
                    currentWindowRight = stack.top() - 1;
                }
                stack.pop();
            };
        }
        maxWindowSoFar = max(maxWindowSoFar, l - currentWindowLeft + 1);
        std::cout << "Can see a valid window: " << s.substr(currentWindowLeft, l - currentWindowLeft + 1) << std::endl;
        l += 1;
    }
    return maxWindowSoFar;
}

int main() {
//    std::cout << lengthOfLongestSubstring("abbxyaczam") << std::endl;
//    std::cout << lengthOfLongestSubstring("abcabcbb") << std::endl;
//    std::cout << lengthOfLongestSubstring("pwwkey") << std::endl;
//    std::cout << lengthOfLongestSubstring("ab") << std::endl;
//    std::cout << lengthOfLongestSubstring("abcabcdxxbb") << std::endl;
//    std::cout << lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << lengthOfLongestSubstring("anviaj") << std::endl;
    return 0;
}
