#include <bits/stdc++.h>
using namespace std;

int T, N, a, b, c;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

viii M;

int main(){
    cin >> T;
    while (T--){
        cin >> N;
        M.resize(N, vii(N, vi(N, 0)));
        for(int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                for (int k = 0; k < N; k++)
                    cin >> M[i][j][k];
            }
        }
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 eng(rd()); // seed the generator
        std::uniform_int_distribution<> distr(1, N);

        int K = N* N;
        int a = 1;
        int b = distr(eng), c=  distr(eng);
        printf("%d\n", K);
        printf("%d %d %d\n", a, b, c);
        int nA = a, nB = b, nC = c, diff = 0;

        for (int i = 1; i < K; i++){
            while (diff != 1){
                nA = distr(eng), nB = distr(eng), nC = distr(eng);
                diff = abs(nA - a) + abs(nB - b) + abs(nC - c);
            }
            a = nA, b = nB, c = nC;
            printf("%d %d %d\n", nA, nB, nC);
        }


    }
    return 0;
}
