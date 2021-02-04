#include <bits/stdc++.h>

template <typename T>
ostream &operator<<(ostream &c, vector<T> &vec) {
    for (auto t : vec) {
        c << t << ' ';
    }
    return c;
}

void reverse(int i, int n, vector<char> &s) {
    if (i > n - 1) {
        return;
    }
    reverse(i + 1, n, s);
    //swap
    if (i > (n / 2) - 1) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
}

void reverseString(vector<char> &s) {
    reverse(0, s.size(), s);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // vector<char> s = {'h', 'e', 'l', 'l', ' ', 'o', 's'};
    // vector<char> s = {'h', 'e', 'l', 'l', ' ', 'o', 's'};
    vector<char> s = {'A', ' ', 'm', 'a', 'n', ',', ' ', 'a', ' ', 'p', 'l', 'a', 'n', ',', ' ', 'a', ' ', 'c', 'a', 'n', 'a', 'l', ':', ' ', 'P', 'a', 'n', 'a', 'm', 'a'};
    std::cout << s << endl;
    reverseString(s);
    std::cout << s << endl;
    return 0;
}
