#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned  llu;

int main()
{
	ios :: sync_with_stdio(false);

    llu T, N, X, Y;
    cin >> T;
    while (T --){

    	cin >> N >> X >> Y;
    	set <llu> moreBetter;
    	set <llu> lessBetter;
    	for (int i = X ; i < N; i ++)
    		moreBetter.insert(i + 1);

    	for (int i = Y; i > 0; i --)
    		lessBetter.insert(N - i);

    	vector<llu> ans;
    	set_union(moreBetter.begin(), moreBetter.end(), lessBetter.begin(),
                lessBetter.end(), inserter(ans, ans.begin()) );
    	cout << ans.size();
    }

    return 0;

}
