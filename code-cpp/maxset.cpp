#include <bits/stdc++.h>
using namespace std;

vector<int> maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans, temp;
    vector<int> :: iterator it = A.begin();
    long long int currBestSum = 0;
    long long int bestminIndex = -1;

    while (it != A.end()){
        if (*it < 0)
            it ++;
        else{
            long long int localSum = 0;
            long long int currIndex = it - A.begin();
            temp.clear();

            while (it != A.end() && *it >= 0){
                localSum += *it;
                temp.push_back(*it);
                it += 1;
            }
            if (localSum > currBestSum){
                ans = temp;
                bestminIndex = currIndex;
                currBestSum = localSum;
            }
            if (localSum == currBestSum && temp.size() > ans.size()){
                ans = temp;
                bestminIndex = currIndex;
                currBestSum = localSum;
            }
        }
    }
    return ans;
}


int main(){
    vector<int> A = {336465782, -278722862, -2145174067, 1101513929, 1315634022, -1369133069, 1059961393, 628175011, -1131176229, -859484421};
    for (auto a : maxset(A)){
        cout << a << " ";
    }
}
