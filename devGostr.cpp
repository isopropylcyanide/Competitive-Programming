#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;
#define MOD 1000000007


ll hamming(string& s1,string& s2){
    return inner_product(s1.begin(), s1.end(), s2.begin(),
        0, plus<ll>(),
        not2(equal_to<string::value_type>())
    );
}



int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    ll testcases, A, K;
    string s;
    cin >> testcases;

    while (testcases--){
        cin >> A >> K;
        cin >> s;

        if (A == 1){ //no need for good strings check if size >= 3
            if (s.size() >= 3)
                cout << 0 << endl;
            else{
                string allA = string(s.size(), 'a');
                ll curDist = hamming(s, allA);

                if (curDist <= K)
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
            }
        }

        else if (A == 2){
            ll m = count(s.begin(), s.end(), 'a') + count(s.begin(), s.end(), 'b');
            ll n = s.size() - m;

            if (n > K)
                cout << 0 << endl;
            else {
                //total string with hamming dist i , i <= k
            }
        }

        else if (A == 3){

		}

    }


    return 0;
}
