#include <bits/stdc++.h>

template <typename T>
ostream& operator<<(ostream& c, vector<T>& vs) {
    for (auto v : vs) {
        c << " -> " << v;
    }
    c << std::endl;
    return c;
}

vector<int> diStringMatch(string s) {
    int small = 0, large = s.size();
    vector<int> ans;
    if (s[0] == 'I') {
        ans.push_back(small++);
    } else {
        ans.push_back(large--);
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'D') {
            //consume largest
            ans.push_back(large--);
        } else {
            //consume smallest
            ans.push_back(small++);
        }
    }
    //fill last entry
    ans.push_back(small);
    return ans;
}

int main() {
    // string s = "IDID";
    // string s = "DDI";
    string s = "I";
    vector<int> ans = diStringMatch(s);
    std::cout << ans << endl;
    return 0;
}