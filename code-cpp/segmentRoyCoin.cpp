#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 1000005

ll N, M, Q, i, j;
vector<ll> start, ending, prefS, prefE;

int main(){
    ios :: sync_with_stdio(false);
    cin >> N;
    cin >> M;
    start.resize(N + 1);
    ending.resize(N + 1);
    prefS.resize(N + 1);
    prefE.resize(N + 1);

    while (M --){
        cin >> i >> j;
        start[i] ++;
        ending[j] ++;
    }
    for (int i = 1; i <= N; i++){
        prefS[i] = prefS[i -1] + start[i];
        prefE[i] += prefE[i -1] + ending[i];
    }

    vector<ll> box;
    for (int i = 1; i <= N; i++)
        box.push_back(start[i] + prefS[i -1] - prefE[i -1]);

    sort(box.begin(), box.end());
    // Now answer queries
    cin >> Q;
    while (Q--){
        cin >> i;
        //how many boxes have at least i coins?
        int ind = lower_bound(box.begin(), box.end(), i) - box.begin();
        cout << box.size() - ind << endl;
    }
}
