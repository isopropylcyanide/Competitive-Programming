#include <bits/stdc++.h>

int expressiveWord(string s, string word) {
    int i = 0, j = 0, n = s.length(), m = word.length();
    if (m > n) {
        return 0;
    } else if (m == n) {
        return 1;
    }
    while (i < n && j < m) {
        if (j < m && s[i] == word[j]) {
            i += 1;
            j += 1;
        } else if (i > 1 && s[i - 2] == s[i - 1] && s[i - 1] == s[i]) {
            i += 1;
        } else if (0 < i && i < n - 1 && s[i - 1] == s[i] && s[i] == s[i + 1]) {
            i += 1;
        } else {
            return false;
        }
    }
    return j == m;
}

int expressiveWords(string s, vector<string>& words) {
    int count = 0;
    for (auto word : words) {
        int ans = expressiveWord(s, word);
        if (ans == 1) {
            std::cout << "Expressive : " << word << endl;
            count += 1;
        }
    }
    return count;
}

int main() {
    vector<string> words = {"hello", "hi", "helo"};
    string s = "heeellooo";
    std::cout << expressiveWords(s, words) << std::endl;

    return 0;
}