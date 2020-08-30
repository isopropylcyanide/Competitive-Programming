#include <bits/stdc++.h>
using namespace std;

string str;
int K;

int removeMinLetters(){
    map<char, int> M;
    vector<int> v; //stores the count
    for (auto s : str)
        M[s] += 1;

    for (auto str : M)
        v.push_back(str.second);
    sort(v.begin(), v.end());

    int i = 0, j = 0, sB = 0;
    int sA = accumulate(v.begin(), v.end(), 0);
    int ans = sA;

    for (i = 0; i < v.size(); i++){
        int mV = v[i] + K;
        while (j < v.size() && v[j] <= mV){
            sA -= v[j];
            j += 1;
        }
        int curAns = sB + sA - (v.size() - j)*mV;
        ans = min(curAns, ans);
        sB += v[i];
    }
    return ans;
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int tests;
    cin >> tests;
    while (tests --){
        cin >> str >> K;
        cout << removeMinLetters() << endl;
    }
    return 0;
}
