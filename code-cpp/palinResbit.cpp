#include <bits/stdc++.h>
using namespace std;

string s;
char x;
int n, q, l, r, c, a;

vector<vector<int>> B;
// A bit that stores count of all 26 characters in the english alphabet

void update(int i, char val, char oldVal=-1){
    // Updates the Bit with the value of val
    s[i++] = val;
    int charNum = val - 'a';
    while (i <= n){
        B[i][charNum] ++;
        if (oldVal != -1)
            B[i][oldVal] -= 1;
        i += (i & -i);
    }
}

void init(string &s){
    B.resize(n + 1, vector<int>(26, 0));
    for (int i = 0; i < s.size(); i++)
        update(i, s[i]);
}

bool canRearrange(int l, int r){
    vector<int> count(26, 0);
    int index = r + 1;
    while (index > 0){
        for(int i = 0; i < B[index].size(); i++)
            count[i] += B[index][i];
        index -= (index & -index);
    }
    index = l;
    while (index > 0){
        for(int i = 0; i < B[index].size(); i++)
            count[i] += B[index][i];
        index -= (index & -index);
    }

    int curOdd = 0;
    bool atmostOneOdd = true;
    for (auto c : count){
        if (c % 2 == 1 && curOdd == 1){
            atmostOneOdd = false;
            break;
        }
        else if (c % 2 == 1)
            curOdd ++;
    }
    return atmostOneOdd;
}


int main(){
    cin >> n >> q;
    cin >> s;

    init(s);
    while(q--){
        cin >> c;
        if (c == 1){
            // Update ath index with x
            cin >> a >> x;
            update(a -1, x, s[a -1] - 'a');
        }
        else{
            // Palindrome rearrangement query
            cin >> l >> r;
            cout << (canRearrange(l -1, r -1) ? "yes" : "no") << endl;
        }
    }

    return 0;
}
