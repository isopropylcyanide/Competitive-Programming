#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005
#define G_MAX 65535

// Calculate nimber of each matrix
// Result of a range is the xor of nimber of each matrix
// Use segtree to store xor in ranges and make point updates

int st[4 * MAX];
int dp[MAX];
int grundy[MAX];
vector<int> visGrundy;

void build(int pos, int l, int r){
        //builds segtree for grundy[] array
        if (l > r)
                return;
        if (l == r) {
                st[pos] = grundy[l];
                return;
        }
        int mid = l + ((r - l) >> 1);
        build(2 * pos + 1, l, mid);
        build(2 * pos + 2, mid + 1, r);
        st[pos] = st[pos*2 +1] ^ st[pos*2 + 2];
}

int query(int pos,int l, int r, int s, int e){
        //query s to e
        if (r < s || l > e || l > r)
                return 0;
        if (s <= l && r <= e)
                return st[pos];
        int mid = l + ((r - l) >> 1);
        return query(pos * 2 + 1, l, mid, s, e) ^
               query(pos * 2 + 2, mid + 1, r, s, e);
}

void update(int pos,int l, int r, int i, int newVal){
        //Update ith with newVal
        if (i < l || i > r)
                return;
        st[pos] ^= (grundy[i] ^ newVal);
        if (l != r) {
                int mid = l + ((r - l) >> 1);
                update(pos * 2 + 1, l, mid, i, newVal);
                update(pos * 2 + 2, mid + 1, r, i, newVal);
        }
}


vector< vector<int> > L(5, vector<int>(5, 0));

bool matrixInside(int a, int b, int c, int d){
        //check if given submatrix lies within original
        for (int i = a; i <= c; ++i) {
                for (int j = b; j <= d; ++j)
                        if(L[i][j] == 0) return 0;
        }
        return 1;
}

int binaryValue(){
        //return the binary value when read as a 16 bit string
        int bin = 0;
        for (int i = 1; i < 5; ++i) {
                for (int j = 1; j < 5; ++j)
                        bin= (bin << 1) + L[i][j];
        }
        return bin;
}

int findGrundy(){
        //Algo that finds grundy Numbers
        int bin = binaryValue();
        set<long long> s;
        if(dp[bin] != -1)
                return dp[bin];

        for (int i = 1; i < 5; ++i) {
                for (int j = 1; j < 5; ++j) {
                        for (int k = i; k < 5; ++k) {
                                for (int l = j; l < 5; ++l) {
                                        if(matrixInside(i, j, k, l)) {
                                                for (int x = i; x <= k; ++x) {
                                                        for (int y = j; y <= l; ++y)
                                                                L[x][y] = 0;
                                                }
                                                s.insert(findGrundy());
                                                for (int x = i; x <= k; ++x) {
                                                        for (int y = j; y <= l; ++y)
                                                                L[x][y] = 1;
                                                }
                                        }
                                }
                        }
                }
        }
        int ans = 0;
        while(s.count(ans))
                ans++;
        return dp[bin] = ans;
}

void precompute(){
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= G_MAX; ++i) {
                if(dp[i] == -1) {
                        visGrundy.clear();
                        for (int j = 15; j >= 0; --j)
                                visGrundy.push_back((i>>j)&1);
                        int kk = 0;
                        for (int k = 1; k < 5; ++k) {
                                for (int j = 1; j < 5; ++j)
                                        L[j][k] = visGrundy[kk++];
                        }
                        findGrundy();
                }
        }
}

void readBinaryMatrix(){
        //read 4 x 4 matrix
        char ch;
        for (int i = 1; i < 5; ++i) {
                for (int j = 1; j < 5; ++j) {
                        cin>>ch;
                        L[i][j]= (int)(ch-'0');
                }
        }
}
int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int testcases, N, M, l, r, pos, choice, ans = 0;
        precompute();

        cin >> testcases;
        while(testcases--) {
                cin >> N >> M;

                //clear segtree
                for (int i = 0; i < 4 *N; i++)
                        st[i] = 0;

                for (int k = 0; k < N; ++k) {
                        readBinaryMatrix();
                        grundy[k] = dp[binaryValue()];
                }
                build(0, 0, N -1);

                while(M--) {
                        cin >> choice;
                        if(choice == 1) {
                                cin >> l >> r;
                                ans = 0;
                                int ans = query(0, 0, N -1, l -1, r -1);
                                cout << (ans == 0 ? "Lotsy" : "Pishty") << "\n";
                        }else{
                                cin >> pos;
                                readBinaryMatrix();
                                int newGrundy = dp[binaryValue()];
                                update(0, 0, N -1, pos -1, newGrundy);
                                grundy[pos -1] = newGrundy;
                        }
                }
        }
        return 0;
}
