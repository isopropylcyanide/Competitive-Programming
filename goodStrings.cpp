#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e5 + 10;
const ll MOD = 1e9 + 7;

ll t, n;
char a[N], b[N];
ll dp[N][3][3];

ll f (ll i, ll a2, ll b2) {
	if (i >= n) return 1;
	if (dp[i][a2][b2] != -1)
        return dp[i][a2][b2];

	ll ans = 0;

	if (a[i] == '1' and b[i] == '1'){
        if (a2 != 1 and b2 != 1)
        ans = (ans + 2 * f(i + 1, 0, 0)) % MOD;
    }

	else if (a[i] != b[i]) {
		if (a2 != 1 and b2 != 2)
            ans = (ans +  f(i + 1, 0, b2 + 1)) % MOD;
		if (a2 != 2 and b2 != 1)
            ans = (ans +  f(i + 1, a2 + 1, 0)) % MOD;
	}

	else if (a2 != 2 and b2 != 2)
            ans = (ans + 2 * f(i + 1, a2 + 1, b2 + 1)) % MOD;

	return dp[i][a2][b2] = ans;
}

int main () {
	scanf("%lld", &t); while (t--) {
		scanf("%s %s", a, b);
		n = strlen(a);

		if (n == 1) {
			puts("2");
			continue;
		}

		if (a[n - 2] == '2' or b[n - 2] == '2') {
			puts("0");
			continue;
		}

		memset(dp, -1, sizeof dp);
		printf("%lld\n", f(0, 0, 0));
	}
	return 0;
}
