#include <bits/stdc++.h>

bool isPowerOfFourBasic(int n) {
    if (n <= 0) {
        return 0;
    }
    double x = log(n) / log(4);
    int _floor = floor(x);
    int _ceil = ceil(x);
    std::cout << x << endl;
    std::cout << _floor << endl;
    std::cout << _ceil << endl;
    return _floor == _ceil;
}

bool isPowerOfFour(int n) {
    int onesInOdd = 0b1010101010101010101010101010101;
    // stringstream res;
    // res << hex << onesInOdd << endl;
    // std::cout << res.str();
    return n > 0 && (n & n - 1) == 0 && ((n & onesInOdd) == n);
}

int main() {
    std::cout << isPowerOfFour(4) << endl;
    std::cout << isPowerOfFour(1304) << endl;
    std::cout << isPowerOfFour(625) << endl;
    std::cout << isPowerOfFour(256) << endl;
    return 0;
}