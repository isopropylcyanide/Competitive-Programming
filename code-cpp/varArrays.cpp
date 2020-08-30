#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
typedef long long unsigned llu;
unordered_set<llu> mySet;

int main() {
    ios :: sync_with_stdio(false);
    llu N, S, P, Q;
    cin >> N >> S >> P >> Q;

    vector<llu> ans(N);
    ans[0] = S  & ((1llu << 31llu) - 1llu);
    mySet.insert(ans[0]);
    for (llu i = 1; i < N; i++){
        ans[i] = (ans[i - 1]*P + Q)  & ((1llu << 31llu) - 1llu);
        mySet.insert(ans[i]);
    }

    cout << mySet.size()<<endl;


    return 0;
}
