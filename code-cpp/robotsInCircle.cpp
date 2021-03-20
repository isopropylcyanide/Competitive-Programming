#include <bits/stdc++.h>

enum direction {
    N,
    S,
    W,
    E
};

//pre compute where robot will move when he moves left from a fixed direction
map<direction, direction> leftDir = {
    {N, W}, {W, S}, {S, E}, {E, N}};

//pre compute where robot will move when he moves right from a fixed direction
map<direction, direction> rightDir = {
    {N, E}, {E, S}, {S, W}, {W, N}};

bool judgeCircle(string instructions) {
    direction dir = N;
    //initial coordinates
    int x = 0, y = 0;
    for (char ch : instructions) {
        if (ch == 'G') {
            if (dir == N || dir == S) {
                //move north or south
                y = dir == N ? y + 1 : y - 1;

            } else if (dir == W || dir == E) {
                //move west or east
                x = dir == W ? x - 1 : x + 1;
            }
        } else if (ch == 'L') {
            dir = leftDir[dir];
        } else {
            dir = rightDir[dir];
        }
    }
    //at origin and not north
    if ((x == 0 && y == 0) || (dir != N)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::cout << judgeCircle("RRDD") << std::endl;
    return 0;
}