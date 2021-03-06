#include <bits/stdc++.h>

bool canBeRemoved(int x, int y, vector<int> &xRange, vector<int> &yRange) {
    for (auto range : xRange) {
        if (x == range) {
            std::cout << " X : " << x << " is within [" << range << "]\n";
            return true;
        }
    }
    for (auto range : yRange) {
        if (y == range) {
            std::cout << " Y : " << y << " is within [" << range << "]\n";
            return true;
        }
    }
    return false;
}

int removeStones(vector<vector<int>> &stones) {
    vector<int> xRange;
    vector<int> yRange;
    int removals = 0;

    for (auto coord : stones) {
        int x = coord[0];
        int y = coord[1];
        if (canBeRemoved(x, y, xRange, yRange)) {
            removals += 1;
        } else {
            //push the x range.. i.e from -infinity
            std::cout << "Never before " << x << ", " << y << endl;
            xRange.push_back(x);
            yRange.push_back(y);
        }
    }
    return removals;
}

int main() {
    vector<vector<int>> stones = {
        {0, 0},
        {0, 2},
        {1, 1},
        {2, 0},
        {2, 2},
    };
    std::cout << removeStones(stones) << std::endl;

    return 0;
}