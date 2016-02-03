#include <bits/stdc++.h>
using namespace std;

#define MAX_MOVES 4llu
typedef long long int llu;

llu solve(deque<char> & op, llu i, llu j, llu moves){
        switch (*(op.begin() + moves)) {
        case '/': return i /j; break;
        case '*': return i *j; break;
        case '+': return i +j; break;
        case '-': return i -j; break;
        }
        return 0;
}

int main(){
        ios :: sync_with_stdio(false);
        llu testcases, N, moves, ans;
        cin >> testcases;

        while (testcases--) {
                cin >> N;
                vector<llu> A(N);

                deque<char> op;
                op.push_back('/');
                op.push_back('*');
                op.push_back('+');
                op.push_back('-');

                for(llu i = 0; i < N; i++)
                cin >> A[i];

                moves = 0, ans = A[0];
                llu i = 0, j = 1;

                while (i < A.size() - 1) {
                        j = i + 1;
                        ans = solve(op, ans, A[j], moves);
                        if (moves == 3){
                            moves = -1;
                            rotate(op.begin(), op.begin() +1, op.end());
                        }
                        moves ++;
                        i ++;
                }
                cout << ans << endl;
        }

        return 0;
}















//
