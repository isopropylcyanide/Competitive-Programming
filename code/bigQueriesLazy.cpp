// new
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define MAX 100005
#define mp make_pair

int T, N, M, X, Y, L, R, type;
pii num[MAX]; //store power of 2 and 5 per number
pii fact[MAX]; //store communlative power of 2 and 5 per number's factorial
pii arr[MAX];

pii st[5 * MAX];

ostream & operator <<(ostream &c, pii &a){
    c << "("<<a.first<<","<<a.second<<") ";
    return c;
}


typedef struct lazyNode{
    int first, second; //denote's one's and two's
    int tStart; //denotes leftbound of start of type2 query in case of Q2
    int empty;
}lazyNode;

ostream & operator <<(ostream &c, lazyNode &a){
    c << "("<<a.first<<","<<a.second<<") " << a.empty << " : " << a.tStart;
    return c;
}

lazyNode lazy2[5 * MAX];
lazyNode lazy1[5 * MAX];


inline int maxPow(int N, int K){
    // Return max power of K in N
    int power = 0;
    while (N % K == 0){
        N /= K;
        power += 1;
    }
    return power;
}

inline void preCompute(){
    // Pre compute power of 2 and 5 in numbers
    num[0] = mp(0, 0);
    fact[0] = num[0];
    for (int i = 1; i < MAX; i++){
        num[i] = mp(maxPow(i, 2), maxPow(i, 5));
        fact[i] = mp(fact[i-1].first + num[i].first , fact[i-1].second + num[i].second);
    }
}

pii mergeNode(pii &a, pii &b){
    return mp(a.first + b.first, a.second + b.second);
}

void constructTree(int pos, int l, int r){
    if (l > r)
        return;
    else if (l == r){
        st[pos] = arr[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    constructTree(pos*2 + 1, l, mid);
    constructTree(pos*2 + 2, mid + 1, r);
    // Merge two nodes
    st[pos] = mergeNode(st[pos*2 + 1], st[pos*2 + 2]);
}

void print(){
    cout << endl;
    for (int i = 0; i < 9; i++)
        cout << "st ["<<i<<"]: " << st[i] << endl;
    cout << endl;

    for (int i = 0; i < 9; i++)
        cout << "l1 ["<<i<<"]: " << lazy1[i] << endl;
    cout << endl;

    for (int i = 0; i < 9; i++)
        cout << "l2 ["<<i<<"]: " << lazy2[i] << endl;
    cout << endl;
}

void removeLazyType2(int pos, int l, int r, int s, int e){
    // type 2 update: replace with lazy's power to range l - r + fact[r] - fact[l -1]
    // cout << "\n L2 lazy: " << l << " to " << r << " : " << st[pos] << endl;
    int ind = lazy2[pos].tStart;
    assert(ind != -1);


    // cout << " L2 f: " <<fact[r - ind + 1].first - fact[l - ind].first<< " + " << (r - l + 1) *lazy2[pos].first << endl;
    // cout << " L2 s: "<<fact[r - ind + 1].second - fact[l - ind].second<<" + " << (r - l + 1)*lazy2[pos].second << endl;
    st[pos].first = (r - l + 1) * lazy2[pos].first;
    st[pos].first += fact[r - ind + 1].first - fact[l - ind].first;
    st[pos].second = (r - l + 1) * lazy2[pos].second;
    st[pos].second += fact[r - ind + 1].second - fact[l - ind].second;
    // cout << " Now node: : " << l <<  ": " << r << " pos: " << pos << " : " << st[pos] << endl;

    if (l != r){
        // lazily inform children of applying a type 1 update first
        lazy2[pos*2 + 1].first = lazy2[pos*2 + 2].first = lazy2[pos].first;
        lazy2[pos*2 + 1].second = lazy2[pos*2 + 2].second = lazy2[pos].second;
        lazy2[pos*2 + 1].tStart = lazy2[pos*2 + 2].tStart = lazy2[pos].tStart;
        lazy2[pos*2 + 1].empty = lazy2[pos*2 + 2].empty = 0;
        // set their lazy1 0
        lazy1[pos*2 + 1].first = lazy1[pos*2 + 1].second = 0;
        lazy1[pos*2 + 1].empty = 1;
        lazy1[pos*2 + 2].first = lazy1[pos*2 + 2].second = 0;
        lazy1[pos*2 + 2].empty = 1;
    }
    // don't forget
    lazy2[pos].empty = 1;
    lazy2[pos].first = lazy2[pos].second = 0;
    lazy2[pos].tStart = -1;
}

void removeLazyType1(int pos, int l, int r, int s, int e){
    // lazy 1 is not empty
    // cout << "\n L1 lazy: " << l << " to " << r << " : " << st[pos] << endl;
    st[pos].first = st[pos].first + (r -l + 1) * lazy1[pos].first;
    st[pos].second = st[pos].second + (r -l + 1) * lazy1[pos].second;
    // cout << " L1 f: " << (r - l + 1) * lazy1[pos].first << endl;
    // cout << " L2 s: " << (r - l + 1) * lazy1[pos].second << endl;
    // cout << " Now node: : " << l <<  ": " << r << " pos: " << pos << " : " << st[pos] << endl;

    if (l != r){
        // lazily inform children of applying a type 1 update first
        lazy1[pos*2 + 1].first += lazy1[pos].first;
        lazy1[pos*2 + 1].second += lazy1[pos].second;
        lazy1[pos*2 + 2].first += lazy1[pos].first;
        lazy1[pos*2 + 2].second += lazy1[pos].second;
        lazy1[pos*2 + 1].empty = lazy1[pos*2 + 2].empty = 0;

    }
    lazy1[pos].first = lazy1[pos].second = 0;
    lazy1[pos].empty = 1;
    lazy1[pos].tStart = -1;
}

void removeLaziness(int pos, int l, int r, int s, int e){
    // check for lazy1
    if (lazy2[pos].empty == 0)
        removeLazyType2(pos, l, r, s, e);

    if (lazy1[pos].empty == 0)
        removeLazyType1(pos, l, r, s, e);
}

void update_1_util(int pos, int l, int r, int s, int e, pii &diff){
    // updates s to e with diff. i.e increment st[pos] with range*diff lazily
    // if lazy node 's type != 0, continue
    removeLaziness(pos, l, r, s, e);

    if (s > r || e < l)
        return;

    // cout << "\nU1  node: : " << l <<  ": " << r << " pos: " << pos << " : " << st[pos] << endl;
    if (s <= l && r <= e){
        // node is within range..since we are multiplying i.e adding powers of two and fives
        // length times, this is apt
        // cout << "\n U1 In range: " << l << " to " << r << " : " << st[pos] << endl;
        // cout << "U1 f: " << (r - l + 1) * diff.first << endl;
        // cout << "U1 s: " << (r - l + 1) * diff.second << endl;
        st[pos].first = st[pos].first + (r -l + 1) * diff.first;
        st[pos].second = st[pos].second + (r -l + 1) * diff.second;
        // cout << " Now node: : " << l <<  ": " << r << " pos: " << pos << " : " << st[pos] << endl;

        if (l != r){
            // lazily inform children of applying a type 1 update first
            lazy1[pos*2 + 1].first += diff.first;
            lazy1[pos*2 + 1].second += diff.second;
            lazy1[pos*2 + 2].first += diff.first;
            lazy1[pos*2 + 2].second += diff.second;
            lazy1[pos*2 + 1].empty = lazy1[pos*2 + 2].empty = 0;
        }
        return;
    }

    int mid = l + ((r - l) >> 1);
    update_1_util(pos*2 + 1, l, mid, s, e, diff);
    update_1_util(pos*2 + 2, mid + 1, r, s, e, diff);
    st[pos] = mergeNode(st[pos*2 + 1], st[pos*2 + 2]);
    // cout << "\nU1 Merged node: : " << l <<  ": " << r << " pos: " << pos << " : " << st[pos] << endl;
}

void query1(int s, int e, int val){
    // Multiply s - e by val
    pii diff = mp(maxPow(val, 2), maxPow(val, 5));
    update_1_util(0, 0, N -1, s, e, diff);
}


void update_2_util(int pos, int l, int r, int s, int e, pii &diff){
    // updates s to e with diff i.e replace st[pos] with diff lazily
    // if lazy node 's type != 0, continue
    removeLaziness(pos, l, r, s, e);

    if (s > r || e < l)
        return;

    // cout << "\nU2 In range node: : " << l <<  ": " << r << " pos: " << pos << " : " << st[pos] << endl;
    if (s <= l && r <= e){
        // node lies within: l` to r`
        // cout << "\n U2 In range Node: " << l << " to " << r << " : " << st[pos] << endl;
        // cout << "U2 first: " << (fact[r - s + 1].first - fact[l -s].first) << " + " << (r - l + 1) * diff.first << endl;
        // cout << "U2 sec: " << (fact[r - s + 1].second - fact[l -s].second)<< " + " << (r - l + 1) * diff.second << endl;
        st[pos].first = (r - l + 1) * diff.first;
        st[pos].first += fact[r - s + 1].first - fact[l -s].first;
        st[pos].second = (r - l + 1) * diff.second;
        st[pos].second += fact[r - s + 1].second - fact[l -s].second;
        // cout << " Now node: : " << l <<  ": " << r << " pos: " << pos << " : " << st[pos] << endl;

        if (l != r){
            // lazily inform children of applying a type 1 update first
            lazy2[pos*2 + 1].first = lazy2[pos*2 + 2].first = diff.first;
            lazy2[pos*2 + 1].second = lazy2[pos*2 + 2].second = diff.second;
            lazy2[pos*2 + 1].tStart = lazy2[pos*2 + 2].tStart = s;
            lazy2[pos*2 + 1].empty = lazy2[pos*2 + 2].empty = 0;
            // set their lazy1 0
            lazy1[pos*2 + 1].first = lazy1[pos*2 + 1].second = 0;
            lazy1[pos*2 + 1].empty = 1;
            lazy1[pos*2 + 2].first = lazy1[pos*2 + 2].second = 0;
            lazy1[pos*2 + 2].empty = 1;
        }
        // don't forget
        return;
    }

    int mid = l + ((r - l) >> 1);
    update_2_util(pos*2 + 1, l, mid, s, e, diff);
    update_2_util(pos*2 + 2, mid + 1, r, s, e, diff);
    st[pos] = mergeNode(st[pos*2 + 1], st[pos*2 + 2]);
    // cout << "\nU2 Merged node: : " << l <<  ": " << r << " pos: " << pos << " : " << st[pos] << endl;
}


void query2(int s, int e, int y){
    // Multiply s - e by k*y
    // product of y * 2y * 3y *... == (fact) powers +(y powers) * length
    pii diff = mp(maxPow(y, 2), maxPow(y, 5));
    update_2_util(0, 0, N -1, s, e, diff);
}


pii query3(int pos, int l, int r, int s, int e){
    // Return nodes lying between s and e
    // cout << "\nIn node: : " << l <<  ": " << r << " pos: " << pos << " : " << st[pos] << endl;
    removeLaziness(pos, l, r, s, e);

    if (s > r || e < l)
        return mp(0, 0);

    if (s <= l && r <= e)
        return st[pos];

    int mid = l + ((r - l) >> 1);
    pii a = query3(pos*2 + 1, l, mid, s, e);
    pii b = query3(pos*2 + 2, mid + 1, r, s, e);
    return mergeNode(a, b);
}

int main(){

    preCompute();

    scanf("%d", &T);
    while (T--){
        scanf("%d %d",&N, &M);

        for (int i = 0; i < MAX; i++)
            arr[i].first = arr[i].second = 0;

        for (int i = 0; i < 5 * MAX; i++){
            lazy1[i].first = lazy1[i].second = 0;
            lazy2[i].first = lazy2[i].second = 0;

            lazy2[i].empty = lazy1[i].empty = 1;
            lazy2[i].tStart = lazy1[i].tStart = -1;

        }
        long long int ans = 0;

        for (int i = 0; i < N; i++){
            scanf("%d", &X);
            arr[i] = mp(maxPow(X, 2), maxPow(X, 5));
        }

        constructTree(0, 0, N -1);
        while (M--){
            scanf("%d", &type);
            switch (type){
            case 1:
                scanf("%d %d %d",&L, &R, &X);
                query1(L -1, R -1, X);
                break;

            case 2:
                scanf("%d %d %d",&L, &R, &Y);
                query2(L -1, R -1, Y);
                break;

            case 3:
                scanf("%d %d",&L, &R);
                pii temp = query3(0, 0, N -1, L -1, R -1);
                int temp2 = min(temp.first, temp.second);
                ans += temp2;
                // cout << " Ans: " << temp2 << " as : " << temp << endl;
                break;
            }
            // print();
        }
        printf("%lld\n", ans);
    }
    return 0;
}
