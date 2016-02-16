#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxVimumGap(const vector<int> &);
};

int Solution::maxVimumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    if (n < 2)
        return 0;

    int minV = *min_element(A.begin(), A.end());
    int maxV = *max_element(A.begin(), A.end());

    // Create n - 1 B
    double gap = ((double)(maxV - minV)) / (n -1);
    vector<pair<int, int> > B(n -1, {-1, -1});

    for (auto v : A){
        if (v == minV || v == maxV)
            continue;
        int idx = (v - minV)/gap;
        if (B[idx].first == -1)
            B[idx].first = v;
        else
            B[idx].first = min(v, B[idx].first);

        B[idx].second = max(B[idx].second, v);
    }

    int maxDiff = 0, lastVal = minV;
    for (auto a : B){
        if (a.first == -1)
            continue;
        maxDiff = max(maxDiff, a.first - lastVal);
        lastVal = a.second;
    }
    maxDiff = max(maxDiff, maxV - lastVal);

    return maxDiff;
}



int main(){
    int N;
    cin >> N ;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    Solution s;
    cout << s.maxVimumGap(A)<<endl;
}
