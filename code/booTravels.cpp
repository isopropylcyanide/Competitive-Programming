#include <bits/stdc++.h>
using namespace std;

#define MAX 20000000
#define M_MAX 100005
#define N_MAX 2005

int N, M;
int S0, P, Q, R;
int W0, X, Y, Z;

int A[N_MAX][M_MAX];
int B[N_MAX][M_MAX];
int S[MAX], W[MAX];
int minP[M_MAX];

void preCompute(){
    // Using sieve of eratosthenes, store the min prime
    vector<int> P(M_MAX, 1);
    P[0] = P[1] = 0;

    for (int i = 1; i < M_MAX; i++)
        minP[i] = i;

    for (int i = 2; i * i < M_MAX; i++){
        if (P[i])
            for (int j = i * i; j < M_MAX; j += i){
                P[j] = 0;
                minP[j] = i;
            }
    }
}

void generateMat(){
    //Generates the required matrices
    S[0] = S0, W[0] = W0;
    for(int i = 0; i < (N*M); i++){
        S[i + 1] = (P * S[i] * S[i] + Q * S[i] + R) % 1000000003;
        A[(i/M) + 1][(i%M) + 1] = S[i + 1];
    }

    for(int i = 0; i < (N*M); i++){
        W[i + 1] = (X * W[i] * W[i] + Y * W[i] + Z) % 1000000003;
        B[(i/M) + 1][(i%M) + 1] = W[i + 1];
    }
}

int findMinCost(){
    // Finds the min Cost associated
    vector<vector<int> > C(N, vector<int>(M, INT_MAX));
    for (int i = 0; i < M; i++)
        C[0][i] = 0;

    for (int i = 0; i < N -1; i++){
        for (int j = 0; j < M; j++){

            for (int k = j; k < M; k++){
                if (j == 0){    //Only move to 1
                    if (k == 0)
                        C[i +1][k] = min(C[i +1][k], C[i][j] + A[i +1][j +1]);
                }
                else{
                    if (minP[j] == minP[k]){
                        if (j == k)
                            C[i +1][k] = min(C[i +1][k], C[i][j] + A[i +1][j +1]);
                        else
                            C[i +1][k] = min(C[i +1][k], C[i][j] + B[i +1][j +1]);
                    }
                }
            }
        }
    }


    int minEl = INT_MAX;
    for (int i = 0; i < M; i++)
        minEl = min(C[N -1][i], minEl);
    return minEl;
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    preCompute();

    cin >> N >> M;
    cin >> S0 >> P >> Q >> R;
    cin >> W0 >> X >> Y >> Z;

    generateMat();
    cout << findMinCost() << endl;

    return 0;
}
