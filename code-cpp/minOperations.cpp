#include <bits/stdc++.h>

template <typename T>
ostream &operator<<(ostream &c, vector<T> &vs) {
    for (auto v : vs) {
        c << v << " -> ";
    }
    c << std::endl;
    return c;
}

vector<int> minOperations(string boxes) {
    int N = boxes.size();
    vector<int> ans(N, 0);
    for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
        ans[i] += ops;
        cnt += boxes[i] == '1' ? 1 : 0;
        ops += cnt;
    }
    for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
        ans[i] += ops;
        cnt += boxes[i] == '1' ? 1 : 0;
        ops += cnt;
    }
    return ans;
}

vector<int> minOperations_(string boxes) {
    vector<int> ans;
    int N = boxes.size();
    vector<int> prefix(N, 0);
    vector<int> oneIndex;

    for (int i = 0; i < N; i++) {
        if (boxes[i] == '1') {
            oneIndex.push_back(i);
        }
    }
    cout << oneIndex;

    for (int i = 0; i < N; i++) {
        int count = 0;
        for (auto oneInd : oneIndex) {
            count += abs(oneInd - i);
        }
        ans.push_back(count);
    }
    return ans;
}

int main() {
    vector<int> ans = minOperations("001011");
    std::cout << ans;
    return 0;
}