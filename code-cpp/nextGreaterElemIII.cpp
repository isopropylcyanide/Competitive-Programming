#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream &operator<<(ostream &c, vector<T> &vec) {
    for (auto t : vec) {
        c << t << ' ';
    }
    return c;
}

int nextGreaterElement(int n) {
    //basically treat it as an array of chars
    vector<int> digits;
    int original = n;
    while (n > 0) {
        int digit = n % 10;
        digits.push_back(digit);
        n = n / 10;
    }
    reverse(digits.begin(), digits.end());
    next_permutation(digits.begin(), digits.end());

    long long newNum = 0;
    bool outLimits = false;
    for (int i = 0; i < digits.size(); i++) {
        newNum += pow(10, digits.size() - 1 - i) * digits[i];
        if (newNum > INT_MAX) {
            outLimits = true;
            break;
        }
    }
    if (newNum > original and !outLimits) {
        return newNum;
    }

    return -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << nextGreaterElement(21) << endl;
    std::cout << nextGreaterElement(12) << endl;
    return 0;
}
