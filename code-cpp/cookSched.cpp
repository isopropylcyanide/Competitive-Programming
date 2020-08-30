#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
        int testCases;
        cin >> testCases;
        while (testCases--) {
                int n, allowed;
                string s;
                cin >> n >> allowed;
                cin >> s;
                int k1 = 0, k2 = 0;

                vector<int> groups;
                int g = 0;
                for(int i = 0; i < n; i++) if (i > 0 && s[i] != s[i - 1]) {
                                groups.push_back(g);
                                g = 1;
                        } else ++g;
                groups.push_back(g);

                for(int i = 0; i < s.length(); i++) {
                        k1 += (s[i] - '0') == i % 2;
                        k2 += (s[i] - '0') != i % 2;
                }
                if (min(k1, k2) <= allowed) {
                        cout << 1 << endl;
                        continue;
                }
                int l = 2, r = n;
                while (l < r) {
                        int mid = (l + r) / 2;
                        int q = 0;
                        for(int g : groups) {
                                q += (g - mid) / (mid + 1) + ((g - mid) % (mid + 1) > 0);
                        }
                        if (q > allowed) l = mid + 1; else r = mid;
                }
                cout << l << endl;
        }
        return 0;
}
