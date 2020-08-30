#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 10005
#define MOD 1000000007

ll N, M, L, T, A, B;

typedef struct node{
    ll l, r, w;
}node;

ostream &operator<<(ostream &c, node &d){
    c << "("<<d.l<<" : "<<d.r<<") - " <<d.w;
    return c;
}
node arr[MAX];

class compare{
public:
    bool operator()(node &a, node &b){
        return (a.w > b.w);
    }
};

ll minCost(){

    priority_queue< node, vector<node>, compare > pq;
    for (int i = 0; i < N; i++)
        pq.push(arr[i]);

    ll minCost = LLONG_MAX;

    // While size of priority queue is more than 1
    while (pq.size() > 0){
        node x = pq.top();
        // cout << "\n x: " << x << endl;
        if (x.l <= L && L <= x.r && x.w <= M)
            minCost = min(minCost, x.w);

        pq.pop();
        //second
        if (pq.size() != 0){
            node y = pq.top();
            // cout << "\n Has y: " << x << endl;
            if (y.l <= L && L <= y.r && y.w <= M)
                minCost = min(minCost, y.w);
            pq.pop();
            node k;
            k.l = x.l + y.l;
            k.r = x.r + y.r;
            k.w = x.w + y.w;
            if (k.l <= L && k.w <= M)
                pq.push(k);
            else{
                if (x.w < y.w)
                    pq.push(x);
                else
                    pq.push(y);
            }
        }

    }

    return minCost;

}


int main(){
    scanf("%lld", &T);
    while (T--){
        scanf("%lld %lld %lld\n", &N, &M, &L);
        memset(arr, MAX, 0);

        for (ll i = 0; i < N; i++)
            scanf("%lld %lld %lld", &arr[i].l, &arr[i].r, &arr[i].w);
        //brute force find items in powerset whose sumcost is less than required
        ll ans = minCost();
        if (ans == LLONG_MAX)
            printf("IMPOSSIBLE\n");
        else
            printf("%lld\n", ans);
    }

    return 0;
}
