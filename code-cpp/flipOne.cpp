#include <bits/stdc++.h>
using namespace std;
/*
   You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.
 */
class Solution
{
public:
vector<int> flip(string);
};

vector<int> Solution::flip(string A) {
        int n = A.length();

        //build new array of 1s and -1s
        vector<int> B(n);
        for(int i = 0; i < n; i ++)
                if(A[i] == '1') B[i] = -1;
                else B[i] = 1;

        //pair storing the answer
        pair<int, int> ans = make_pair(INT_MAX, INT_MAX);

        //basic kadane's algorithm implementation
        //we also storing the begin point for best till now
        int best_till_now = 0,best_ending_here = 0, l = 0;
        for(int i = 0; i< n; i++) {
                if (best_ending_here + B[i] < 0) {
                        l = i + 1;
                        best_ending_here = 0;
                }
                else best_ending_here += B[i];
                if (best_ending_here > best_till_now) {
                        best_till_now = best_ending_here;
                        ans.first = l;
                        ans.second = i;
                }
        }
        //if no valid subarray found
        if(ans.first==INT_MAX) return vector<int>();
        //return answer
        vector<int> ret;
        ret.push_back(ans.first+1);
        ret.push_back(ans.second+1);
        return ret;
}


int main(){
        int N;
        string S;
        cin >> S;
        Solution s;

        vector<int> ans = s.flip(S);

        return 0;
}
















//
