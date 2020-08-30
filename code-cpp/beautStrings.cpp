#include <bits/stdc++.h>
using namespace std;

const int N = 1000500;

string s;
int p[N];
char c[N];
long long f[3][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin >> s;
  int idx = 0;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
      if (s[i] == s[i + 1] && i + 1 < n) {
          p[1 + idx]++;
      } else {
          c[1 + idx] = s[i], p[1 + idx++]++;
      }
  }
  n = idx;
  f[0][0] = 1LL;
  for (int i = 0; i < n; ++i) {
      f[0][i + 1] += f[0][i];
      f[1][i + 1] += f[1][i];
      f[2][i + 1] += f[2][i];
      if (p[i + 1] >= 2) {
          f[2][i + 1] += f[0][i];
      }
      if (p[i + 1] >= 1) {
          if (i + 2 <= n && p[i + 1] == 1 && c[i] == c[i + 2]) {
              f[2][i + 2] -= 1;
          }
          f[1][i + 1] += f[0][i];
          f[2][i + 1] += f[1][i];
      }
  }
  cout << f[2][n] << endl;
  return 0;
}
