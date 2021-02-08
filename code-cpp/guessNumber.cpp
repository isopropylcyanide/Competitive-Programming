#include <bits/stdc++.h>

/**
* I pick a number from 1 to n. You have to guess which number I picked.
*/
int pick = 6;

int guess(int num) {
    if (num > pick) {
        return 1;
    } else if (num == pick) {
        return 0;
    } else {
        return -1;
    }
}

int guessNumber(int n) {
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int res = guess(mid);

        if (res == 0) {
            return mid;
        } else if (res == 1) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return pick;
}

int main() {
    std::cout << guessNumber(10) << endl;
    return 0;
}
