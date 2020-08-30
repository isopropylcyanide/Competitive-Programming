#include <bits/stdc++.h>
using namespace std;

/*Given a string consisting of letters, '', '' and '', we can perform the following operation: Take any two adjacent distinct characters and replace them with the third character. For example, if a and  b are adjacent, they can replaced by c. Find the smallest string which we can obtain by applying this operation repeatedly?
*/

int stringReduction(string &s){
    int fA = count(s.begin(), s.end(), 'a');
    int fB = count(s.begin(), s.end(), 'b');
    int fC = count(s.begin(), s.end(), 'c');
    int n = s.size();

    if (fA == n || fB == n || fC == n)
        return n;

    else if ((fA % 2 == 0 && fB % 2 == 0 && fC %2 == 0) ||
              (fA % 2 == 1 && fB % 2 == 1 && fC %2 == 1))
        return 2;
    else
        return 1;
}

int main(){
    int testcases;
    cin >> testcases;
    string s;

    while(testcases --){
        cin >> s;
        cout << stringReduction(s) << endl;
    }

    return 0;
}
