#include <bits/stdc++.h>

/**
 * Given an array of size n, find the max within the min of its sliding windows of size k
*/

template <typename T>
ostream& operator<<(ostream& c, deque<T> vs) {
    for (auto v : vs) {
        c << " -> " << v;
    }
    c << std::endl;
    return c;
}

int segment(int x, vector<int> space) {
    int globalMax = INT_MIN;
    int n = space.size();
    std::deque<int> minElems(x);

    for (int i = 0; i < x; i++) {
        //insert into the deque
        // if new elem is smaller then the push backs have no chance
        while (!minElems.empty() && space[minElems.back()] >= space[i]) {
            minElems.pop_back();
        }
        minElems.push_back(i);
    }

    globalMax = max(globalMax, space[minElems.front()]);
    for (auto i : minElems) {
        std::cout << "[" << i << "] : " << space[i] << " -> ";
        std::cout << endl;
    }
    // std::cout << minElems;
    for (int i = x; i < n; i++) {
        //remove all elements which are smaller than index i
        while (!minElems.empty() && minElems.front() <= i - x) {
            minElems.pop_front();
        }
        //same logic
        while (!minElems.empty() && space[minElems.back()] >= space[i]) {
            minElems.pop_back();
        }
        minElems.push_back(i);
        globalMax = max(globalMax, space[minElems.front()]);

        std::cout << "*********\n";
        for (auto i : minElems) {
            std::cout << "[" << i << "] : " << space[i] << " -> ";
            std::cout << endl;
        }
    }
    return globalMax;
}

int main() {
    // vector<int> grid = {8, 2, 4, 6};
    // vector<int> grid = {1, 2, 3, 1, 2};
    vector<int> grid = {3, 8, 1, 9, 0, 7, -1};
    std::cout << segment(4, grid) << endl;
    return 0;
}