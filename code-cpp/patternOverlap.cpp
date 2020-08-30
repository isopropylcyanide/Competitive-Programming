// memoize
#include <bits/stdc++.h>
using namespace std;

string x, y;
int t, n, m, ans;

int dp[2010][2010];

int match(int i, int j){
        // printf("Match %d %d\n",i, j);
        int ans = dp[i][j];
        if (ans != -1)
                return ans;

        if (i == n && j == m)
                ans = 1;

        else if (i > n ||  j > m)
                ans = 0;

        else if (x[i] == '*' && y[j] == '*') {
                ans = match(i + 1, j + 1) ||  match(i + 1, j + 2)
                      ||  match(i + 1, j + 3) ||  match(i + 1, j + 4)
                      ||  match(i + 2, j + 1) ||  match(i + 3, j + 1)
                      || match (i, j + 1) || match(i + 1, j) ||  match(i + 4, j + 1);

        }

        else if (x[i] == '*') {
                ans = match(i + 1, j + 1) ||  match(i + 1, j + 2)
                      ||  match(i + 1, j + 3) ||  match(i + 1, j + 4)
                      ||  match(i + 1, j);
        }

        else if (y[j] == '*') {
                ans = match(i + 1, j + 1) ||  match(i + 2, j + 1)
                      ||  match(i + 3, j + 1) ||  match(i + 4, j + 1)
                      ||  match(i, j + 1);

        }

        else if (x[i] == y[j])
                ans = match(i + 1, j + 1);
        else
                ans = 0;

        dp[i][j] = ans;
        // printf("SToring dp[%d][%d] as %d\n",i,j,ans );
        return ans;
}


int main(){

        scanf("%d", &t);
        for  (int i = 1; i <= t; i++) {
                memset(dp, -1, sizeof(dp));
                cin >> x;
                cin >> y;
                n = x.size();
                m = y.size();
                ans = match(0, 0);

                printf("Case #%d: %s\n",i, ans == 1 ? "TRUE" : "FALSE" );
        }


        ans = 0;
}
