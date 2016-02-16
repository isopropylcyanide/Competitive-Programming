#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> repeatedNumber(const vector<int> &A);
};

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    int set_bit_no;
    int i, xor1 = A[0];
    int x = 0, y = 0, n = A.size();

    for(i = 1; i < n; i++)
        xor1 = xor1 ^ A[i];

    int expectedXorN = (n & ( (n & 1) -1) )| ( (n & 1) ^ ( (n & 3) >> 1) ) ;
    xor1 = xor1 ^ expectedXorN;

    set_bit_no = xor1 & ~(xor1-1);

    for(i = 0; i < n; i++){
        if(A[i] & set_bit_no)
            x = x ^ A[i]; /* A[i] belongs to first set */
        else
            y = y ^ A[i]; /* A[i] belongs to second set*/
    }

    for(i = 1; i <= n; i++){
        if(i & set_bit_no)
            x = x ^ i; /* i belongs to first set */
        else
            y = y ^ i; /* i belongs to second set*/
    }

    int xCount = 0, yCount = 0;
    for (auto a : A){
        if (a == x){
            xCount += 1;
            if (xCount == 2){
                ans.push_back(x);
                ans.push_back(y);
                return ans;
            }
        }
        else if (a == y){
            yCount += 1;
            if (yCount == 2){
                ans.push_back(y);
                ans.push_back(x);
                return ans;
            }
        }
    }

    return ans;
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    Solution s;

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    for (auto a : s.repeatedNumber(A))
        cout << a <<" -> ";
    cout << endl;

    return 0;
}
















//
