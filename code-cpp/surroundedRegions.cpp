#include <bits/stdc++.h>

/*
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 */

template <typename T>
ostream &operator<<(ostream &c, vector<T> &vs) {
    for (auto v : vs) {
        c << " -> " << v;
    }
    return c;
}

template <typename T>
ostream &operator<<(ostream &c, vector<vector<T>> &vs) {
    for (auto v : vs) {
        c << " { " << v << " } \n";
    }
    return c;
}

typedef pair<int, int> pii;
std::set<pii> visited;

bool inBounds(int i, int j, int n, int m) {
    return (i >= 0 && i < n) && (j >= 0 && j < m);
}

int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

void bfs(int i, int j, int n, int m, vector<vector<char>> &board) {
    queue<pii> q;

    visited.insert(make_pair(i, j));

    q.push(make_pair(i, j));

    while (!q.empty()) {
        std::cout << "halla";
        pii node = q.front();

        for (int dir = 0; dir < 4; dir++) {
            int new_i = node.first + dir_x[dir];
            int new_j = node.second + dir_y[dir];
            if (inBounds(new_i, new_j, n, m) && board[new_i][new_j] == 'O') {
                if (visited.find(make_pair(new_i, new_j)) == visited.end()) {
                    q.push(make_pair(new_i, new_j));
                    visited.insert(make_pair(new_i, new_j));
                }
            }
        }
        q.pop();
    }
}
void solve(vector<vector<char>> &board) {
    int n = board.size();
    if (n < 1) {
        return;
    }
    int m = board[0].size();

    // dfs from all 0's on border. Whichever are reachable, add them to a set
    //search "O" from top and last row
    for (int j = 0; j < m; j++) {
        if (board[0][j] == 'O') {
            bfs(0, j, n, m, board);
        }
        if (board[n - 1][j] == 'O') {
            bfs(n - 1, j, n, m, board);
        }
    }

    //search "O" from first and last column
    for (int i = 0; i < n; i++) {
        if (board[i][0] == 'O') {
            bfs(i, 0, n, m, board);
        }
        if (board[i][m - 1] == 'O') {
            bfs(i, m - 1, n, m, board);
        }
    }
    // render board and change O to X if they are visited
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O' && visited.find(make_pair(i, j)) == visited.end()) {
                board[i][j] = 'X';
            }
        }
    }
    std::cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
    //                               {'X', 'O', 'O', 'X'},
    //                               {'X', 'X', 'O', 'X'},
    //                               {'X', 'O', 'X', 'X'}};

    vector<vector<char>> board =
        {{'O', 'O'},
         {'O', 'O'}};

    std::cout << board;
    solve(board);
    std::cout << board;
    return 0;
}
