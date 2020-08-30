//short
#include <bits/stdc++.h>
using namespace std;

/*parse table Range Maximum Query
    Space : O(N)(M)(log N)(log M)
    Query : O(1)
    Also answers the range Sum query in the immmutable matrix
 */
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi A; //the original 2D vector
int P[10][10][1000][1000];
int N, M;

void preprocessMaximum(){
    for (int i = 0 ; (1<<i) <= N; i += 1){
        for(int j = 0 ; (1<<j) <= M ; j += 1){
            for (int x = 0 ; x + (1<<i) -1 < N; x+= 1){
                for (int y = 0 ;  y + (1<<j) -1 < M; y+= 1){
                    if (i == 0 and j == 0)
                        P[i][j][x][y] = A[x][y]; // store x, y
                    else if (i == 0)
                        P[x][y][i][j] = max(P[i][j-1][x][y], P[i][j-1][x][y+(1<<(j-1))]);
                    else if (j == 0)
                        P[i][j][x][y] = max(P[i-1][j][x][y], P[i-1][j][x+ (1<<(i-1))][y]);
                    else
                        P[i][j][x][y] = max(max(P[i-1][j-1][x][y], P[i-1][j-1][x + (1<<(i-1))][y]),                   max(P[i-1][j-1][x][y+(1<<(j-1))], P[i-1][j-1][x + (1<<(i-1))][y+(1<<(j-1))]));
                    // cout << "from i="<<x<<" j="<<y<<" of length="<<(1<<i)<<" and length="<<(1<<j) <<"max is: " << P[i][j][x][y] << endl;
                }
            }
        }
    }
}

int rangeMaxQuery(int x, int y, int x1, int y1){
    int k = log2(x1 - x + 1);
    int l = log2(y1 - y + 1);
    // cout << "Value of k="<<k<<" l="<<l<<endl;
    int ans = max(max(P[k][l][x][y], P[k][l][x1 - (1<<k) + 1][y]), max(P[k][l][x][y1 - (1<<l) + 1], P[x1 - (1<<k) + 1][y1 - (1<<l) + 1][k][l]));
    return ans;
}

int main(){
    A = {
        {11, 3, 4, 5, 6},
        {7, 8, 9, 10, 11},
        {-4, 4, 14, 2, 2},
        {3, 2, 8, 1, 0},
        {9, 16, 30, 2, -7},
        {3, 1, 4, 6, 2}
    };
    N = A.size();
    M = A[0].size();

    preprocessMaximum();

    for (auto a : A){
        for (auto b : a)
            cout << " " << b;
        cout << endl;
    }

    int a, b, c, d;
    while (true){
        cout << "\n Find MAX between M[a][b] and M[c][d] inclusive\t";
        cin >> a >> b >> c >> d;
        cout << "\n Max: " << rangeMaxQuery(a, b, c, d) << endl;
    }

}
