#include <bits/stdc++.h>

/**
* We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are
* rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 
* and 7 are rotated 180 degrees, they become invalid.
*
* A confusing number is a number that when rotated 180 degrees becomes a different
* number with each digit valid.(Note that the rotated number can be greater than
* the original number.)
*
* Given a positive integer N, return the number of confusing numbers between 1 and N
* inclusive.
*/

set<int> rotatableDigits = {0, 1, 6, 8, 9};
map<int, int> rotation = {
    make_pair(0, 0),
    make_pair(1, 1),
    make_pair(6, 9),
    make_pair(8, 8),
    make_pair(9, 6)};

void f(int number, int N, int &count, int rotatedNumber, int digit) {
    if (number != rotatedNumber) {
        //this number is invalid..further would be too
        count = count + 1;
    }
    //this number is valid
    //try its new entries and their rotations?
    for (auto i : rotatableDigits) {
        //see if adding this makes it a different number than N
        int newNumber = number * 10 + i;
        if (newNumber > N) {
            break;
        }
        f(newNumber, N, count, rotation[i] * digit + rotatedNumber, digit * 10);
        //try and rotate the newNumber..you just need to check if even a single
        //6 or 9 is present.
    }
}

int confusingNumberII(int N) {
    //I'm thinking backtracking here
    //basically I can either rotate or not
    //at each stage I can add digits while the obtained number <= N
    int count = 0;
    f(1, N, count, 1, 10);
    f(6, N, count, 9, 10);
    f(8, N, count, 8, 10);
    f(9, N, count, 6, 10);
    return count;
    //handle special for N < 10
}

int main() {
    std::cout << confusingNumberII(20) << endl;
    std::cout << confusingNumberII(100) << endl;
    std::cout << confusingNumberII(1000) << endl;
    return 0;
}
