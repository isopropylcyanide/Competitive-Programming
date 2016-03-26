#include <bits/stdc++.h>
using namespace std;

int N, M;

//A is input matrix, L is left max marsh, U is max up marsh
vector< vector<char> > A;
vector< vector<int> >  L, U;

void preComputeLeft(){
    //Precompute left matrix
    for (int i = 0; i < M; i ++){
        for (int j = 0; j < N; j++){
            if (A[i][j] == 'x')
                L[i][j] = -1;
            else{
                int count = 0, k = j -1;
                while (k >= 0 && A[i][k--] == '.')
                    count ++;
                L[i][j] = count;
            }
        }
    }
}

void preComputeUp(){
    //Precompute UP matrix
    for (int i = 0; i < M; i ++){
        for (int j = 0; j < N; j++){
            if (A[i][j] == 'x')
                U[i][j] = -1;
            else{
                int count = 0, k = i -1;
                while (k >= 0 && A[k--][j] == '.')
                    count ++;
                U[i][j] = count;
            }
        }
    }
}

void sieveEros(){
    std::vector<int> prime;
    int maX = 10000;
    prime.resize(maX, 1);
    prime[0] = prime[1] = 0;

    for (int i = 2; i < maX; i++){
        if (prime[i]){
            for (int j = i * i; j < maX; j += i)
                prime[j] = 0;
        }
    }

    for (int i = 0; i < 100; i++)
        cout << i <<" => "<< ((prime[i] == 1) ? "Prime\n" : "Not Prime\n") ;
}

int main(){
    ios :: sync_with_stdio(false);
    cin >> M >> N;
    A.resize(M, vector<char>(N));
    L.resize(M, vector<int>(N));
    U.resize(M, vector<int>(N));

    for (int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            cin >> A[i][j];

    preComputeLeft();
    preComputeUp();
    int maxPeri = -1;


    for (int rA = 0; rA < M; rA++){
        for (int rB = rA + 1; rB < M; rB++){
            vector<int> v;
            int rowDiff = rB - rA;

            for (int j = 0; j < N; j++){
                if (U[rB][j] >= rowDiff)
                    v.push_back(j);
            }
            int l = 0;
            for (auto col : v){
                int minLeft = col - min(L[rA][col], L[rB][col]);
                while (v[l] < minLeft)
                    l ++;

                if (col > v[l])
                    maxPeri = max(maxPeri, 2 * (rowDiff + col - v[l]));
            }
        }
    }

    if (maxPeri == -1)
        cout << "impossible\n";
    else
        cout << maxPeri << endl;
    return 0;
}
