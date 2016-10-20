#include<bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;
typedef pair<int, int> pll;
vector<pll> A;
int N, a, b;

ll dist(pll &a, pll&b){
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

ll solve(){
    ll n = A.size();
    ll  maxDist = 0;
    for (int i = 0; i < n -1; i++){
        for (int j = i + 1; j < n; j++)
            maxDist = max(maxDist, dist(A[i], A[j]));
    }
    return maxDist;
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> a >> b;
        A.push_back(make_pair(a, b));
        cout << solve() << endl;
    }

    return 0;
}
