#include <bits/stdc++.h>

enum direction {
    N,
    S,
    W,
    E
};

map<direction, direction> leftDir = {
    {N, W}, {W, S}, {S, E}, {E, N}};

map<direction, direction> rightDir = {
    {N, E}, {E, S}, {S, W}, {W, N}};

bool judgeCircle(string instructions) {
    direction dir = N;
    int x = 0, y = 0;
    for (char ch : instructions) {
        if (ch == 'G') {
            if (dir == N) {
                y += 1;
            } else if (dir == S) {
                y -= 1;
            } else if (dir == W) {
                x -= 1;
            } else if (dir == E) {
                x += 1;
            }
        } else if (ch == 'L') {
            dir = leftDir[dir];
        } else {
            dir = rightDir[dir];
        }
    }
    // cout << x << " and " << y << endl;
    if (x == 0 && y == 0 || (dir != N)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::cout << judgeCircle("RRDD") << std::endl;
    return 0;
}