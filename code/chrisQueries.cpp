#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;

ll N, M, Q, u, v, pos, type, id;
vector <string> S, P;
char ch;

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    S.resize(N);

    for (int i = 0; i < N; i++)
        cin >> S[i];

    cin >> M;
    P.resize(M);

    for (int i = 0; i < M; i++)
        cin >> P[i];

    cin >> Q;
    while (Q--){
        cin >> type;
        if (type == 1){
            // type id pos newchar, change P[id][pos] = newchar
            cin >> id >> pos >> ch;
            P[id -1][pos -1] = ch;
        }
        else if (type == 2){
            //type id char
            cin >> id >> ch;
            P[id - 1] += ch;
        }
        else{
            //type id
            //print number of nice strings that have id as substring
            cin >> id;
            ll count = 0;
            for (auto nice : S){
                if (nice.find(P[id - 1]) != string::npos)
                    count++;
            }
            cout << count << endl;
        }
    }

    return 0;
}
