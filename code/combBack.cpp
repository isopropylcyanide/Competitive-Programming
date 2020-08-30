#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        Solution(){}
        vector<vector<int> > combine(int, int);
};

void combineUtil(int i, vector<int> &S, set<vector<int> > &L, const int k, const int n){
    if (S.size() == k){
        L.insert(S);
        S.clear();
        return;
    }

    for(int j = i +1; j <= n; j++){
        vector<int> B1(S);
        B1.push_back(j);
        vector<int> B2(S);
        combineUtil(j, B1, L, k, n);
        combineUtil(j, B2, L, k, n);
    }
}

vector<vector<int> > Solution::combine(int n, int k) {
    vector< vector<int> > ans;
    set<vector<int> > L;
    vector<int> S;
    combineUtil(0, S, L, k, n);

    for (auto a : L)
        ans.push_back(a);
    return ans;
}


int main(){
    int n, k;
    cin >> n >> k;
    Solution().combine(n, k);
    return 0;
}
