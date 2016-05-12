#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;
ll T, B, W;

ll nearestPow(ll N){
    ll power = 0;
    while (N){
        N /= 2;
        power ++;
    }
    return pow(2, power);
}

void adjacencyBuild(){
    //Print graph
    vector< vector<int> > M(B, vector<int>(B, 0));

    ll nearPow = nearestPow(W);

    for (int i = 0; i < B -1; i++){
        ll curPow = pow(2, B - i - 2);

        if (curPow > W && curPow != nearPow)
            M[i][i +1] = 1;

        else if (curPow > W && curPow == nearPow){
            M[i][i +1] = 1;
            ll diff = curPow - W;
            ll end = B - 2;
            vector<int> bin;
            while (diff){
                bin.push_back(diff %2);
                diff /= 2;
            }

            for (auto a : bin){
                M[i][end] = a;
                end --;
            }
        }

        else{
            // do all normal stuff
            for (int k = 1; k + i < B; k++)
                M[i][i + k] = 1;
        }
    }

    for (auto a : M){
        for (auto b : a)
            cout << b;
        cout << endl;
    }

}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (ll i = 0; i < T; i++){
        cin >> B >> W;
        cout << "Case #" << i + 1 << ": ";

        if (W > pow(2, B -2))
            cout << "IMPOSSIBLE\n";
        else{
            cout << "POSSIBLE\n";
            adjacencyBuild();
        }

    }

    return 0;
}
