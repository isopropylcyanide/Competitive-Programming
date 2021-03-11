#include <bits/stdc++.h>

string removeKdigits(string num, int k) {
    stack<int> st;
    string ans = "";

    if (k == 0) {
        return num;
    }
    for (int i = 0; i < num.size(); i++) {
        int digit = num[i] - '0';
        while (!st.empty() && st.top() > digit && k > 0) {
            st.pop();
            k -= 1;
        }
        if (!st.empty() || digit != 0) {
            //its a zero
            st.push(digit);
        }
    }
    while (!st.empty() && k > 0) {
        st.pop();
        k -= 1;
    }
    while (!st.empty()) {
        ans += (st.top() + '0');
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans == "" ? "0" : ans;
}

int main() {
    // std::cout << removeKdigits("1432219", 3) << endl;
    // std::cout << removeKdigits("10200", 1) << endl;
    // std::cout << removeKdigits("10", 1) << endl;
    // std::cout << removeKdigits("112", 1) << endl;
    std::cout << removeKdigits("1001", 2) << endl;
    return 0;
}