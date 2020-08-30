#include <bits/stdc++.h>
using namespace std;

string s, x;
int N;
vector<int> nonStar, counts;
int m[3001][26];

int solve(){
    for (auto pos : nonStar){
        // cout << "\n pos: " << pos << " s[pos]: " << s[pos] << " : " << int(s[pos]) - 97;
        int match = m[pos][int(s[pos]) - 97];
        counts.push_back(match);
    }
    sort(counts.begin(), counts.end());
    if (counts.size() <= 1)
        return N;
    return counts[1];
}

int main(){
    ios :: sync_with_stdio(false);
    cin >> s;
    cin >> N;

    for (int i = 0; i < s.size(); i++){
        if (s[i] != '*')
            nonStar.push_back(i);
    }

    for (int i = 0; i < N; i++){
        cin >> x;
        for (int j = 0; j < s.size(); j++)
            m[j][int(x[j]) - 97]++;
    }
    cout << solve() << endl;

}
