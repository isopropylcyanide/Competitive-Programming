#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;
string n;
ll k, t;

int main(){
    ios :: sync_with_stdio(false);
    cin >> t;
    while (t--){
        cin >> n;
        cin >> k;

        ll ans = 0;
        for (auto a : n)
            ans = (ans * 10 + a - '0') % k;
        cout << ans << endl;
    }

    return 0;
}
