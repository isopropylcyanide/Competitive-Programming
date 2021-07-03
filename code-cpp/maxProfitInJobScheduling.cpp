#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * You're given the startTime, endTime and profit arrays, return the maximum profit you can
 * take such that there are no two jobs in the subset with overlapping time range.
 */

int findNextIndex(int i, vector<int> &startTime, int value) {
    //find the next index in start time that is greater than i but has a val >= value
    if (i < 0 || i >= startTime.size()) {
        return -1;
    }
    auto pos = lower_bound(startTime.begin(), startTime.end(), value);
    if (pos == startTime.end()) {
        return -1;
    }
    int dist = distance(startTime.begin(), pos);
    if (dist <= i) {
        return -1;
    }
    return dist;
}

int f(int i, vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
    int next = findNextIndex(i, startTime, endTime[i]);
    int maxProfit = profit[i];
    if (next == -1) {
        // there's no index that can suffice so, we start
        return maxProfit;
    }
    // else profit is the max of all profit
    int inclProfit = 0;
    for (int idx = next; idx < startTime.size(); idx++) {
        // we try including this, adding its value
        // either we include this index or not
        // if we
        int profitHere = f(idx, startTime, endTime, profit);
        cout << "For i: " << i << " profit at next idx : " << idx << " : " << profitHere << "\n";
        inclProfit = max(inclProfit, profitHere);
        cout << "For i: " << i << " profit max so far at next idx: " << idx << " : " << inclProfit << "\n";
    }
    cout << "For i: " << i << " overallProfit: " << inclProfit + maxProfit << "\n";
    cout << "********\n";
    return maxProfit + inclProfit;
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
    // base case
    if (startTime.size() == 1) {
        return profit[0];
    }
    int ans = profit[0];
    for (int i = 0; i < startTime.size(); i++) {
        ans = max(ans, f(i, startTime, endTime, profit));
    }
    return ans;
}

int main() {
    vector<int> start = {1, 2, 3, 4, 6};
    vector<int> end = {3, 5, 10, 6, 9};
    vector<int> profit = {20, 20, 100, 70, 60};
    cout << jobScheduling(start, end, profit) << endl;

//    vector<int> start = {1, 2, 3, 3};
//    vector<int> end = {3, 4, 5, 6};
//    vector<int> profit = {50, 10, 40, 70};
//    cout << jobScheduling(start, end, profit) << endl;

//    vector<int> start = {1, 1, 1};
//    vector<int> end = {2, 3, 4};
//    vector<int> profit = {5, 6, 4};
//    cout << jobScheduling(start, end, profit) << endl;

    return 0;
}
