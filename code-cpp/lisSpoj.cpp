#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, N;
vector<ll> A;

ll nlogn_lis(vector<ll> &A, ll N){
    //report the length of the lis in O(nlogn) time
    vector<ll> I(N + 1, 0);
    ll length = 1;
    I[1] = A[0];

    for (ll i = 1; i < N; i++){
        //find the upper bound for A[i] in length array
        ll upper = upper_bound(I.begin() + 1, I.begin() + 1 + length, A[i] -1) - I.begin();
        //if upperbound > length, increment length
        I[upper] = A[i];
        if (upper > length)
            length++;

        for (int i = 1; i <= N; i++)
            cout << I[i] << " ";
        cout << endl;
    }
    return length;
}

int main(){
    scanf("%lld", &N);
    A.resize(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    printf("%lld\n", nlogn_lis(A, N));

    return 0;
}
