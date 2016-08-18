#include <bits/stdc++.h>
using namespace std;

//A number is called Round number if its non-negative and its first and last
// digits are same. For example 0 , 3 , 343 and 50005

typedef long long ll;

ll n, q, l, r, c, a, x;
vector<ll> A;
vector<vector<ll>> B;
// A bit that stores count of all 26 characters in the english alphabet

ll extractLastDigit(ll N){
    return N % 10;
}

ll extractFirstDigit(ll N){
    while(N > 9)
        N /= 10;
    return N;
}

void update(ll i, ll val, ll oldVal = LLONG_MAX){
    // Updates the Bit with the value of val
    A[i++] = val;
    bool isRound = true;
    ll dig = extractLastDigit(val);
    if (val < 0 || extractFirstDigit(val) != dig)
        isRound = false;

    bool oldwasRound = true; ll oldDig;
    if (oldwasRound < 0)
        oldwasRound = false;
    else{
        oldDig = extractLastDigit(oldVal);
        if (extractFirstDigit(oldVal) != oldDig)
            oldwasRound = false;
    }

    while (i <= n){
        if (isRound)
            B[i][dig] ++;
        if (oldVal != LLONG_MAX && oldwasRound)
            B[i][oldDig]--;
        i += (i & -i);
    }
}

void init(vector<ll> &A){
    B.resize(n + 1, vector<ll>(10, 0));
    for (ll i = 0; i < A.size(); i++)
        update(i, A[i]);
}

ll getSum(int i){
    i++;
    ll count = 0;
    while(i > 0){
        for (auto x : B[i])
            count += x;
        i -= (i & -i);
    }
    return count;
}

ll queryRound(ll l, ll r){
    return getSum(r) - getSum(l -1);
}


int main(){
    cin >> n >> q;
    A.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> A[i];

    init(A);

    while(q--){
        cin >> c;
        if (c == 2){
            // Update ath index with x
            cin >> a >> x;
            update(a -1, x, A[a -1]);
        }
        else{
            //query total round numbers in the range
            cin >> l >> r;
            cout << queryRound(l -1, r -1) << endl;
        }
    }

    return 0;
}
