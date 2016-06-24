#include <bits/stdc++.h>
using namespace std;

int N, M, Q, a, b;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;

vvi A, S; //the original 2D vector and sum 2d
int P[1000][1000][10][10];

// ------------- RANGE MAX QUERY 2D Starts -----------------
void preprocessMaximum(){
    for (int i = 0 ; (1<<i) <= N; i += 1){
        for(int j = 0 ; (1<<j) <= M ; j += 1){
            for (int x = 0 ; x + (1<<i) -1 < N; x+= 1){
                for (int y = 0 ;  y + (1<<j) -1 < M; y+= 1){
                    if (i == 0 and j == 0)
                        P[x][y][i][j] = A[x][y]; // store x, y
                    else if (i == 0)
                        P[x][y][i][j] = max(P[x][y][i][j-1], P[x][y+(1<<(j-1))][i][j-1]);
                    else if (j == 0)
                        P[x][y][i][j] = max(P[x][y][i-1][j], P[x+ (1<<(i-1))][y][i-1][j]);
                    else
                        P[x][y][i][j] = max(max(P[x][y][i-1][j-1], P[x + (1<<(i-1))][y][i-1][j-1]),                   max(P[x][y+(1<<(j-1))][i-1][j-1], P[x + (1<<(i-1))][y+(1<<(j-1))][i-1][j-1]));
                    // cout << "from i="<<x<<" j="<<y<<" of length="<<(1<<i)<<" and length="<<(1<<j) <<"max is: " << P[x][y][i][j] << endl;
                }
            }
        }
    }
}

int rangeMaxQuery(int x, int y, int x1, int y1){
    int k = log2(x1 - x + 1);
    int l = log2(y1 - y + 1);
    // cout << "Value of k="<<k<<" l="<<l<<endl;
    int ans = max(max(P[x][y][k][l], P[x1 - (1<<k) + 1][y][k][l]), max(P[x][y1 - (1<<l) + 1][k][l], P[x1 - (1<<k) + 1][y1 - (1<<l) + 1][k][l]));
    return ans;
}
// ------------- RANGE MAX QUERY 2D Ends -----------------


// ------------- RANGE SUM QUERY 2D Starts -----------------
void preprocessSum(){
    //Preprocess matrix S to get the running sum in O(1)
    int n = A.size(), m = A[0].size();
    S.resize(n, vi(m, 0));
    S[0][0] = A[0][0];

    for (int j = 1; j < m; j++)
        S[0][j] = S[0][j -1] + A[0][j];

    for (int i = 1; i < n; i++)
        S[i][0] = S[i -1][0] + A[i][0];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            S[i][j] = S[i -1][j] + S[i][j -1] - S[i -1][j -1] + A[i][j];
}



int rangeSumQuery(int x1, int y1, int x2, int y2){
    //Using the preprocessed matrix, find the sum of [x1][y1] to [x2][y2]
    if (x1 == 0 && y1 == 0)
    return S[x2][y2];
    else if (x1 == 0)
    return S[x2][y2] - S[x2][y1 - 1];
    else if (y1 == 0)
    return S[x2][y2] - S[x1 -1][y2];
    else
    return S[x2][y2] - S[x1 -1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1];
}
// ------------- RANGE SUM QUERY 2D Ends -----------------


void solve(int a, int b){
    int smartMin = INT_MAX;
    int numElem = a * b;

    for (int r = 0; r <= N - a; r++){
        for (int c = 0; c <= M - b; c++){
            int maxSmart = rangeMaxQuery(r, c, r + a -1, c + b -1);
            int sumSmart = rangeSumQuery(r, c, r + a -1, c + b -1);
            smartMin = min(smartMin, abs(numElem * maxSmart - sumSmart));
        }
    }
    cout << smartMin << endl;
}

void input(){
    cin >> N >> M;
    A.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    preprocessMaximum();
    preprocessSum();

    cin >> Q;
    while (Q--){
        cin >> a >> b;
        solve(a, b);
    }
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}
