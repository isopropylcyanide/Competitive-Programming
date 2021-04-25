#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, temp;
    cin >> N;
    vector<int> H(N + 1, 0);

    for (int i = i + 1; i <= N; i++) {
        cin >> temp;
        H[i] = temp;
    }

    stack<int> st;
    int tos, max_area, new_area;

    int i = 1;
    for (; i <= N; i++) {
        if (st.empty() || H[st.top()] <= H[i])
            st.push(i);
        else {
            tos = st.top();
            st.pop();
            new_area = H[tos] * (st.empty() ? i : i - st.top() - 1);
            if (max_area < new_area)
                max_area = new_area;
        }
    }

    while (st.empty() == false) {
        tos = st.top();
        st.pop();
        new_area = H[tos] * ((st.empty() ? i : i - st.top() - 1));

        if (max_area < new_area)
            max_area = new_area;
    }

    cout << max_area << endl;

    return 0;
}
