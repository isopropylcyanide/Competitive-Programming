#include <bits/stdc++.h>
#include <iostream>


#define Max int(1e7)
using namespace std;

// Counting Sort
int main(){
    ios::sync_with_stdio(false);
    
    int n, temp;
    string s; 
    vector<string> ar[100];
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> temp >> s;
        if (i < n/2)
            ar[temp].push_back("-");
        else
            ar[temp].push_back(s);

    }

    for(int i = 0; i < 100; ++ i)
        for(int j = 0; j < ar[i].size(); ++ j)
            cout << ar[i][j] << " ";
    
    cout << endl;

    return 0;
}