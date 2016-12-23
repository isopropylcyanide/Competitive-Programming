#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll n, m;
	cin >> n >> m;

	ll nimsum = 0;
	for (ll i = 0; i < m; ++i) {
		ll x, k = 0;
		cin >> x;

		if (x > 0)
			while ((x & 1) == 0){
                k++;
                x >>= 1;
            }


		nimsum ^= k;
	}

	if (nimsum != 0)
		printf("First\n");
	else
		printf("Second\n");

}
