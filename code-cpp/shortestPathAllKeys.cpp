#include <bits/stdc++.h>

typedef pair<int, int> pii;
typedef pair<pii, bitset<6>> pb;
typedef pair<pb, int> pbi;
#define mp make_pair

set<char> keys = {'a', 'b', 'c', 'd', 'e', 'f'};
set<char> locks = {'A', 'B', 'C', 'D', 'E', 'F'};
map<char, char> lockKeys = {
    {'A', 'a'},
    {'B', 'b'},
    {'C', 'c'},
    {'D', 'd'},
    {'E', 'e'},
    {'F', 'f'}};

bool shouldVisit(int i, int j, int n, int m, set<pii> visited) {
    if (i >= 0 && i < n && j >= 0 && j < m) {
        if (visited.find(mp(i, j)) == visited.end()) {
            return true;
        }
    }
    return false;
}

int getBit(char ch) {
    int ascii = int(ch);
    if (ascii < 90) {
        std::cout << "Bit for " << ch << " : " << (ascii % 65) << endl;
        return ascii % 65;
    }
    std::cout << "Bit for " << ch << " : " << (ascii % 97) << endl;
    return ascii % 97;
}

int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

int shortestPathAllKeys(vector<string>& grid) {
    //do a bfs but also maintain a bitset
    //where's my starting point again
    queue<pbi> q;
    set<char> foundKeys;

    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '@') {
                q.push(mp(mp(mp(i, j), 0), 0));
            } else if (keys.find(grid[i][j]) != keys.end()) {
                foundKeys.insert(grid[i][j]);
            }
        }
    }
    //now let's bfs from each
    int bestAns = INT_MAX;
    int numKeys = foundKeys.size();
    set<pii> visited;

    while (!q.empty()) {
        pbi top = q.front();
        q.pop();
        //if we have a better solution
        //if the bitset is reached, we are good
        int ans = top.second;
        bitset b = top.first.second;
        int i = top.first.first.first;
        int j = top.first.first.second;
        std::cout << " At [" << i << "," << j << "] : {" << grid[i][j] << "} with Bitset " << b << " with steps: " << ans << endl;
        visited.insert(mp(i, j));

        if (b == ((1 << numKeys) - 1)) {
            //all keys are acquired?
            bestAns = min(ans, bestAns);
        } else {
            //see if we can moving
            //try up
            for (int dir = 0; dir < 4; dir++) {
                int new_i = i + dir_x[dir];
                int new_j = j + dir_y[dir];
                if (shouldVisit(new_i, new_j, n, m, visited)) {
                    char ch = grid[new_i][new_j];
                    if (ch != '#') {
                        if (ch == '.') {
                            q.push(mp(mp(mp(new_i, new_j), b), ans + 1));
                        }
                        //can potentially visit
                        //if lower, collect key
                        else if (keys.find(ch) != keys.end()) {
                            bitset newBitset = b;
                            newBitset.set(getBit(ch));
                            q.push(mp(mp(mp(new_i, new_j), newBitset), ans + 1));

                        } else {
                            //if uppercase, it's a lock
                            //we need to check key. if we do not,
                            int bit = getBit(ch);
                            if (b.test(bit)) {
                                //we can proceed as we have the key
                                q.push(mp(mp(mp(new_i, new_j), b), ans + 1));
                            }
                        }
                        //if all above, then and only then push to queue
                    }
                }
            }
        }
    }
    return bestAns == INT_MAX ? -1 : bestAns;
}

int main() {
    // vector<string> grid = {
    //     "@.a.#",
    //     "###.#",
    //     "b.A.B"};
    // vector<string> grid = {
    //     "@..aA",
    //     "..B#.",
    //     "....b"};
    vector<string> grid = {
        "@...a",
        ".###A",
        "b.BCc"};
    std::cout << "Answer is " << shortestPathAllKeys(grid) << endl;
    return 0;
}