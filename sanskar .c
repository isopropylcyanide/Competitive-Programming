#include <algorithm>
#include <cstdio>
using namespace std;
 
typedef long long llu;
 
int next_int()
{
        int n = 0;
        char c = getchar_unlocked();
        while (!('0' <= c && c <= '9'))
        {
                c = getchar_unlocked(); 
        }
        while ('0' <= c && c <= '9')
        {
                n = (n<<3)+(n<<1) + c - '0';
                c = getchar_unlocked();
        }
        return n;
}



int power_exp(int a,int p)
{
    llu RES = 1;
    llu MOD = 1000000007;
    llu B = (llu) a;
    while(p > 0)
    {
        if(p%2 == 1) RES = (RES*B)%MOD;
        B = (B*B)%MOD;
        p = p/2;
    }
    int res = (int) RES;
    return res;
}


#define MX 25
#define MS 2100000
int m;
llu a[MX], s;
int c[MX], d[MX];
int flg[MS], cnt[MS][MX];
int v[MX][MS], vc[MX];
int val[MS];
 
void Find(int k, int state, llu sum) {
	int i;
	
	if (k == m) {
		flg[state] = (sum == s);
		for (i = 0; i < m; i++) {
			cnt[state][i] = d[i];
			if (flg[state] && d[i]) v[i][vc[i]++] = state;
		}
		return;
	}
	state *= c[k];
	for (i = 0; i < c[k]; i++) {
		d[k] = i;
		Find(k + 1, state, sum);
		state++, sum += a[k];
	}
}
 
int Can(int state) {
	int& rlt = val[state];
	int i, j, k, state1, state2;
	
	if (rlt != -1) return rlt;
	if (flg[state]) return rlt = 1;
	k = -1;
	for (i = 0; i < m; i++) {
		if (!cnt[state][i]) continue;
		if (k == -1 || vc[k] > vc[i]) k = i;
	}
	for (j = 0; j < vc[k]; j++) {
		state1 = v[k][j];
		state2 = 0;
		for (i = 0; i < m; i++) {
			d[i] = cnt[state][i] - cnt[state1][i];
			if (d[i] < 0) break;
			state2 = state2 * c[i] + d[i];
		}
		if (i < m) continue;
		if (Can(state2)) return rlt = 1;
	}
	return rlt = 0;
}
 
int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int tn, n, k, i, j, tot;
	
	for (scanf("%d", &tn); tn--; ) {
		scanf("%d%d", &n, &k);
		for (s = i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
			s += a[i];
		}
		if (!s) {
			puts((n >= k) ? "yes" : "no");
			continue;
		}
		if (s % k) {
			puts("no");
			continue;
		}
		
		s /= k;
		sort(a, a + n);
		for (m = i = 0; i < n; i = j) {
			for (j = i + 1; j < n; j++) {
				if (a[j] > a[i]) break;
			}
			if (!a[i]) continue;
			a[m] = a[i];
			c[m++] = j - i + 1;
		}
		tot = 1;
		for (i = 0; i < m; i++) tot *= c[i];
		fill_n(flg, tot, 0);
		fill_n(vc, m, 0);
		Find(0, 0, 0);
		fill_n(val, tot, -1);
		puts(Can(tot - 1) ? "yes" : "no");
	}
	return 0;
}


