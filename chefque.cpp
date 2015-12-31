#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long unsigned llu;
#define mod 4294967296llu

vector<bool> inserts(mod/2,false);

int main(){

    ios::sync_with_stdio(false);

    llu Q,S1,A,B;
    llu element, finalSum = 0llu,key;

    cin >> Q >> S1 >> A >> B;

    while(Q--){
        key = S1/2llu;
        if( S1%2llu)
        {
            if(inserts[key] == false)
            {
                inserts[key] = true;
                finalSum += key;
            }
        }
        else
        {
            if(inserts[key] == true)
            {
                inserts[key] = false;
                finalSum -= key;
            }
        }
        S1 = (A*S1+ B)%mod;
    }

    cout<<finalSum<<endl;
    return 0;
}