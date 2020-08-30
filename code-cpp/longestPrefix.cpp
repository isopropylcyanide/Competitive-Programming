#include <bits/stdc++.h>
using namespace std;

int longestCommonPrefix(int l, int h, vector<string> &str) {
        vector<string> strs;
        for (int i = l; i <= h; i++)
            strs.push_back(str[i]);
        if(strs.size() == 0)
            return 0;
        string minStr = strs[0];

        for(int i = 1; i < strs.size(); i++){
            if(strs[i].size() < minStr.size())
                minStr=strs[i];
        }
        int end = minStr.size();
        for(int i = 0; i < strs.size(); i++){
            int j;
            for( j = 0; j < end; j++){
                if(minStr[j] != strs[i][j])
                    break;
            }
            if(j < end)
                end = j;
        }
        return end ;
}

int LCPrefix(vector<string> &A, int B) {
    int count = 0;
    for (int i = 0; i < A.size(); i++){
        for (int j = i; j < A.size(); j++){
            if (longestCommonPrefix(i, j, A) >= B)
                count = count + 1;
        }
    }
    return count;
}

int main(){

    vector<string> A = {
        "a",
        "aman",
        "bc",
        "bcd"
    };
    cout << LCPrefix(A, 1) << endl;
    cout << LCPrefix(A, 2) << endl;
    cout << LCPrefix(A, 3) << endl;
    cout << LCPrefix(A, 4) << endl;

    return 0;
}
