#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int> spiralOrder(const vector<vector<int> > &);
};

// dir => 0 : TOP
// dir => 1 : DOWN
// dir => 2 : BOTTOOM
// dir => 3 : UP

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
        vector<int> result;

        int m = A.size(), n = A[0].size();
        int T = 0, B = m -1, L = 0, R = n -1;
        int dir = 0;

        while (T <= B && L <= R){
            if (dir == 0){
                for (int i = L; i <= R; i++)
                    result.push_back(A[T][i]);
                T ++;
                dir = 1;
            }

            else if (dir == 1){
                for (int i = T; i <= B; i++)
                    result.push_back(A[i][R]);
                R --;
                dir = 2;
            }

            else if (dir == 2){
                for (int i = R; i >= L; i--)
                    result.push_back(A[B][i]);
                B --;
                dir = 3;
            }

            else if (dir == 3){
                for (int i = B; i >= T; i--)
                    result.push_back(A[i][L]);
                L ++;
                dir = 0;
            }
        }

        return result;

}

int main(){

        vector<vector<int> > A(4);
        A[0] = {2, 4, 6, 8};
        A[1] = {5, 9, 12, 16};
        A[2] = {2, 11, 5, 9};
        A[3] = {3, 2, 1, 8};

        Solution s;
        for (auto a : s.spiralOrder(A))
                cout << a << " ";

        cout << endl;
        return 0;
}
