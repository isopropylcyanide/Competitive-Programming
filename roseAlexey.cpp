#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 100005

ll v[MAX];
multiset<ll> mSet;

int main() {
	ll t;
    scanf("%lld", &t);

	while (t--) {
		ll n, k;
        scanf("%lld %lld", &n, &k);

		for (ll i = 0; i < n; i++)
			scanf("%lld", v + i);

		sort(v, v+n);
        mSet.clear();

		ll ind = 0;
		for (ll i = 0; i < k; i++) {
			ll j = n - i - 1;
            ind = v[j] == v[j + 1] ? ind + 1 : 1;
		}

		mSet.insert(ind);
		ll lastVal = v[n - k];
		if (ind == k) {
			ind = 0;
			lastVal = 0;
		}

		for (ll i = n-k-1; i >= 0; i--) {
            ind = v[i] == v[i + 1] ? ind + 1 : 1;

			if (i%k) {
                //not divisible. replace from the set
				if (lastVal == v[i]) {
					auto it = mSet.lower_bound(ind-1);
					mSet.erase(it);
					mSet.insert(ind);
					if (ind == k)
						ind = lastVal = 0;
					continue;
				}
				if ((v[i] != v[i-1] or ind == k) and *(mSet.begin()) < ind) {
					mSet.erase(mSet.begin());
					mSet.insert(ind);
				}
				if (ind == k)
                    ind = 0;
			}
            else {
                //divisible. insert into mset
				mSet.insert(ind);
				lastVal = v[i];
				if (ind == k)
					lastVal = ind = 0;
			}
		}
		ll resp = 0;
		for (auto it : mSet)
			resp += k - it;

        printf("%lld\n", resp);
	}
	return 0;
}
