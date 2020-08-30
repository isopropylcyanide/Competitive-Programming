#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long int ll;
// Output maximum sum sub array of length n  mod m

int main(){
    ios::sync_with_stdio(false);
    
    ll testcases, n, m, temp;
    vector<ll> a;
    vector<ll> prefix;

    cin >> testcases;

    while (testcases --){
        cin >> n >> m;

        set<ll> s;
        ll pre_sum = 0;
        s.insert(0);

        ll maximum = -1;
        for (ll i = 0; i < n; i++){
            cin >> temp;
            pre_sum = (pre_sum + temp)%m ;

            maximum = max(maximum, pre_sum);
            set<ll> :: iterator it;

            it = s.lower_bound(pre_sum + 1);
            if (it != s.end())
                maximum = max(maximum, pre_sum - *it + m);

            s.insert(pre_sum);
        }

        cout << maximum << endl;
     
     }

    return 0;
}

