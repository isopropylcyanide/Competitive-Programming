#include<bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;

ll T;
ll n, k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    string first = "Arpa";
    string second = "Dishant";

    while (T--){
        cin >> n >> k;
        // if (n <= 2){
        //     cout << first << endl;
        //     continue;
        // }        
        cout << ((n % (k + 1) == 0) ? second : first);
    }
    
    return 0;
}