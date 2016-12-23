#include <bits/stdc++.h>
using namespace std;

const int  MOD = 1e9 + 7;
string s;
string f;
int  t;

void getZarr(string str, int  Z[]){
    //  Fiint s Z array for given string str[]
    int  n = str.length();
    int  L, R, k;

    // [L,R] make a window which matches with prefix of s
    L = R = 0;
    for (int  i = 1; i < n; ++i){
        // if i>R nothing matches so we wiint  calculate naively.
        if (i > R){
            L = R = i;
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else{
            k = i-L;
            if (Z[k] < R-i+1)
                 Z[i] = Z[k];
            else{
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

int  findIndex(int  h, int  x, vector<int> &ind){
    // find last item in ind from l to h incl that is <= x
    auto it = upper_bound(ind.begin(), ind.begin() +  h , x);
    return it == ind.begin() ? -1 : distance(ind.begin(), it - 1);
}

int  findSize(vector<int> &ind, int  patLen){
    // finds the required size;
    int  n = ind.size();
    if (n == 0)
        return 0;
    vector<int > dp(n, 0);
    dp.clear();
    dp[0] = 1;

    for (int  i = 1; i < n; i++){
        if (ind[i] - ind[i -1] >= patLen)
            dp[i] = ((dp[i -1] * 2) % MOD + 1) % MOD;
        // else find the first j such that ind[i] - ind[j] >= patLen
        else{
            int  x = ind[i] - patLen;
            int  j = findIndex(i - 1, x, ind);
            // cout << "\n for i: " << i << " in 0 to " << i -1 << " and " << x << " -> j: " << j << endl;
            if (j >= 0)
                dp[i] = (dp[i -1] + dp[j] + 1) % MOD;
            else
                dp[i] = (dp[i -1] + 1) % MOD;
        }
    }
    return dp[n -1] % MOD;
}


//  print s aint  occurrences of pattern in text using Z algo
int  search(string &text, string &pattern){
    // Create concatenated string "P$T"
    string concat = pattern + "$" + text;
    int  l = concat.length();
    int  patLen = pattern.length();

    // Construct Z array
    int  Z[l];
    getZarr(concat, Z);

    //  now looping through Z array for matching condition
    vector<int> ind;
    for (int  i = 0; i < l; ++i){
        // if Z[i] (matched region) is equal to pattern
        // length  we got the pattern
        if (Z[i] == pattern.length()){
            ind.push_back(i - pattern.length() -1);
        }
    }
    return findSize(ind, patLen);
}


int main(){
    cin >> t;
    while(t --){
        cin >> s >> f;
        if (s.back() == '\n')
            s.pop_back();
        if (f.back() == '\n')
            f.pop_back();
        // prepare z array with s as text and f as pattern
        cout << search(s, f) << "\n";
    }

    return 0;
}
