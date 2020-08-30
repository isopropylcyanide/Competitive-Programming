#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

    int t;
    string s;

    cin >> t;
    while (t--){

       cin >> s;
       bool last_perm = true;
       int start = 0;

       for (int i = 0; i < s.size() - 1;  i++)
            if (s[i] < s[i+1]){
                last_perm = false;
                start = i;
            }

       if (last_perm){
        cout << "no answer\n";
        continue;
        }

        int end = -1;
        for (int j = start +1; j < s.size(); j++)
            if (s[start] < s[j])
                end = j;

        swap(s[start],s[end]);
        string new_s = s.substr(start +1,s.size());

        sort(new_s.begin(),new_s.end());

        for (int j = start +1; j < s.size(); j++)
            s[j] = new_s[j - start - 1];

        cout << s<<endl;

    }


    return 0;
}