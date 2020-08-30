#include<bits/stdc++.h>
using namespace std;

string s, t;
int n;

bool matches(int length){
    int endIndex = n - length;
    int i = 0;
    while (endIndex < n){
        if (s[endIndex++] != t[i++]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s >> t;
    
    int minAns = n;
    
    for (int i = 1; i < n; i++){
        if (matches(i)){
            minAns = n - i;
            // break;
        }
    }
    cout << minAns << "\n";
    return 0;
}
