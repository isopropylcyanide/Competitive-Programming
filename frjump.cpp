#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef long long ll;
int N, Q, first;
vector<int> F;

inline ll firstDigit(ll n){
    while (n > 9)
        n /= 10;
    return n;
}

tuple<ll, ll> loopSum(ll start, ll skip){
    ll sum = 1, first = 0;
    bool flag = false;

    for (ll i = start; i < N; i += skip){
        if (sum * F[i] > mod){
            first = firstDigit(sum);
            flag = true;
            sum = (sum * F[i]) % mod;
        }
        else
            sum *= F[i];
    }
    if (!flag)
        first = firstDigit(sum);
    return make_tuple(first,sum);
}

int main(){
    cin.tie(NULL);
    ios :: sync_with_stdio(false);

    cin >> N;
    F.resize(N);
    for (int i = 0; i < N; i++)
        cin >> F[i];

    cin >> Q;
    ll a, p, f, r;


    while (Q --){
        cin >> a;
        if (a == 1){
            cin >> p >> f;
            F[p -1] = f;
        }
        else{ //find R
            cin >> r;
            tie(p, f) = loopSum(0, r);
            cout << p << " " << f << endl;
        }
    }

    return 0;
}
