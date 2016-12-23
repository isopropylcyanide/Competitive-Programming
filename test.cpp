#include <bits/stdc++.h>
using namespace std;

#define CLR(a, b) memset(a, (b), sizeof(a))
#define ll o<<1
#define rr o<<1|1
typedef long long LL;

const int MAXN = 1e5 +10;
const int MOD = 1e9 + 7;

void add(LL &x, LL y){
     x += y;
     x %= MOD;
 }

struct Tree {
    int l, r, sum, Min;
};

Tree tree[MAXN<<2];

void pushup(int o) {
    tree[o].sum = tree[ll].sum + tree[rr].sum;
    tree[o].Min = min(tree[ll].Min, tree[rr].Min);
}

void build(int o, int l, int r) {
    tree[o].l = l; tree[o].r = r;
    if(l == r) {
        tree[l].sum = tree[l].Min = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    build(ll, l, mid); build(rr, mid+1, r);
    pushup(o);
}

void update(int o, int pos, int v) {
    if(tree[o].l == tree[o].r) {
        tree[o].sum = tree[o].Min = v;
        return ;
    }
    int mid = (tree[o].l + tree[o].r) >> 1;
    if(pos <= mid) update(ll, pos, v);
    else update(rr, pos, v);
    pushup(o);
}

int query(int o, int L, int R, int op) {
    if(tree[o].l == L && tree[o].r == R)
        return op == 1 ? tree[o].sum : tree[o].Min;

    int mid = (tree[o].l + tree[o].r) >> 1;
    if(R <= mid) return query(ll, L, R, op);
    else if(L > mid) return query(rr, L, R, op);
    else {
        if(op == 1) {
            return query(ll, L, mid, op) + query(rr, mid+1, R, op);
        }
        else {
            return min(query(ll, L, mid, op), query(rr, mid+1, R, op));
        }
    }
}

struct Edge {
    int from, to, next;
};

Edge edge[MAXN<<1];
int head[MAXN], edgenum;

void init(){
    edgenum = 0;
    CLR(head, -1);
}

void addEdge(int u, int v) {
    Edge E = {u, v, head[u]};
    edge[edgenum] = E;
    head[u] = edgenum++;
}

int son[MAXN], num[MAXN];
int top[MAXN], pos[MAXN], id;
int dep[MAXN], pre[MAXN];

void DFS1(int u, int fa, int d) {
    dep[u] = d;
    pre[u] = fa;
    num[u] = 1;
    son[u] = -1;
    for(int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if(v == fa) continue;
        DFS1(v, u, d+1);
        num[u] += num[v];
        if(son[u] == -1 || num[son[u]] < num[v])
            son[u] = v;
    }
}

void DFS2(int u, int T) {
    top[u] = T; pos[u] = ++id;
    if(son[u] == -1) return ;
    DFS2(son[u], T);
    for(int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if(v == pre[u] || v == son[u]) continue;
        DFS2(v, v);
    }
}

int GetSum(int u, int v) {
    int f1 = top[u], f2 = top[v];
    int ans = 0;
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) {
            swap(u, v);
            swap(f1, f2);
        }
        ans += query(1, pos[f1], pos[u], 1);
        u = pre[f1], f1 = top[u];
    }
    if(u == v) return ans;
    if(dep[u] > dep[v]) swap(u, v);
    return ans += query(1, pos[son[u]], pos[v], 1);
}

int GetMin(int u, int v) {
    int f1 = top[u], f2 = top[v];
    int ans = 1;
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) {
            swap(u, v);
            swap(f1, f2);
        }
        ans = min(query(1, pos[f1], pos[u], 2), ans);
        u = pre[f1], f1 = top[u];
    }
    if(u == v) return ans;
    if(dep[u] > dep[v]) swap(u, v);
    return min(ans, query(1, pos[son[u]], pos[v], 2));
}

int s[MAXN], e[MAXN];

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        init();
        for(int i = 1; i <= n-1; i++) {
            scanf("%d%d", &s[i], &e[i]);
            addEdge(s[i], e[i]);
            addEdge(e[i], s[i]);
        }
        DFS1(1, -1, 1);
        id = 0;
        DFS2(1, 1);
        build(1, 1, id);

        for(int i = 1; i <= n-1; i++) {
            if(dep[s[i]] > dep[e[i]])
                swap(s[i], e[i]);
            update(1, pos[e[i]], 1);
        }

        int Q; scanf("%d", &Q);
        while(Q--) {
            int op, x, y;
            scanf("%d", &op);
            if(op == 1) {
                scanf("%d", &x);
                update(1, pos[e[x]], 1);
            }
            else if(op == 2) {
                scanf("%d", &x);
                update(1, pos[e[x]], 0);
            }
            else {
                scanf("%d%d", &x, &y);
                if(GetMin(x, y) == 0) {
                    printf("-1\n");
                }
                else {
                    printf("%d\n", GetSum(x, y));
                }
            }
        }
    }
    return 0;
}
