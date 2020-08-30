#include<bits/stdc++.h>
using namespace std;

const int nax = 1e6 + 5;
char sl[nax];
const char W[5] = "ACTG";
int n, cnt[4];

bool ok() {
    for(int i = 0; i < 4; ++i)
        if(cnt[i] > n / 4)
            return false;
    return true;
}

int f(int i) {
    for(int j = 0; j < 4; ++j)
        if(sl[i] == W[j])
            return j;
    assert(false);
}

int main() {
    scanf("%d", &n);
    scanf("%s", sl);
    for(int i = 0; i < n; ++i)
        ++cnt[f(i)];

    for (auto a : cnt)
        cout << a << " -> ";
    cout << endl;

    if(ok()) { // already steady
        puts("0");
        return 0;
    }

    int ans = n;
    // two pointers i, j
    int j = 0;
    for(int i = 0; i < n; ++i) {
        while(j < n && !ok())
            --cnt[f(j++)];
        if(ok()) ans = min(ans, j - i);
        ++cnt[f(i)];
    }
    printf("%d\n", ans);
    return 0;
}




//
