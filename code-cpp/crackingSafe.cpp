#include <bits/stdc++.h>

bool dfs(string &s, unordered_set<string> &visited, int maxPossible, int n, int k) {
    if (visited.size() == maxPossible) {
        return true;
    } else {
        for (int i = 0; i < k; i++) {
            // for (int i = k; i >= 0; i--) {
            //add an edge for each of the k edges
            s.push_back('0' + i);
            string cur = s.substr(s.size() - n);
            //if the edge before isn't seen, it is of interest to us
            if (visited.find(cur) == visited.end()) {
                visited.insert(cur);

                if (dfs(s, visited, maxPossible, n, k)) {
                    return true;
                }
                visited.erase(cur);
            }
            //remove the new edge
            s.pop_back();
        }
        return false;
    }
}

string crackSafe(int n, int k) {
    int maxPossible = pow(k, n);
    string ans(n, '0');
    unordered_set<string> visited;
    visited.insert(ans);

    dfs(ans, visited, maxPossible, n, k);
    return ans;
}

int main() {
    std::cout << crackSafe(2, 3) << endl;
    return 0;
}