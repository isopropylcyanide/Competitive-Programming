#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool hotel(vector<int> &, vector<int> &, int);
};

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K){
    if(K == 0)
        return false;
    int N = arrive.size();

    vector<pair<int, int> > vec;
    for(int i = 0; i < N; ++i) {
        vec.push_back(make_pair(arrive[i], 1));
        vec.push_back(make_pair(depart[i], 0));
    }

    sort(vec.begin(), vec.end());

    int curActive = 0;
    int maxAns = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].second == 1) { // arrival
           curActive++;
           maxAns = max(maxAns, curActive);
        }
        else curActive--;
    }

    if (K >= maxAns) return true;
    return false;
}


int main(){
    int A, B, K;
    cin >> A >> B >> K;
    vector<int> arr(A);
    vector<int> dep(B);
    for (int i = 0; i < A; i++)
        cin >> arr[i];

    for (int i = 0; i < B; i++)
        cin >> dep[i];
    Solution s;
    cout << s.hotel(arr, dep, K);
}
