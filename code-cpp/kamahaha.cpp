#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <map>
#include <vector>
using namespace std;

const int maxn = 1000;

vector<int> adj[maxn];
int mark[maxn], stamp, match[maxn];

// Hungray, find augment path
inline bool augment(int x)
{
    for (int i = 0; i < adj[x].size(); ++ i) {
        int y = adj[x][i];
        if (mark[y] == stamp) {
            continue;
        }
        mark[y] = stamp;
        if (match[y] == -1 || augment(match[y])) {
            match[y] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    int T;
    for (scanf("%d", &T); T --;) {
        int n;
        scanf("%d", &n);
        assert(1 <= n <= maxn);
        map<int, int> hashX, hashY;
        for (int i = 0; i < n; ++ i) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (!hashX.count(x)) {
                int newid = hashX.size();
                adj[newid].clear();
                hashX[x] = newid;
            }
            x = hashX[x];
            if (!hashY.count(y)) {
                int newid = hashY.size();
                hashY[y] = newid;
            }
            y = hashY[y];
            adj[x].push_back(y);
        }
        memset(mark, -1, sizeof(mark));
        memset(match, -1, sizeof(match));
        stamp = 0;
        int maxMatch = 0;
        for (int i = 0; i < hashX.size(); ++ i) {
            ++ stamp;
            if (augment(i)) {
                ++ maxMatch;
            }
        }
        printf("%d\n", maxMatch);
    }
    return 0;
}
