#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;
vector<ll> A, B;
ll T, N;

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--){
        cin >> N;
        A.resize(N);
        B.resize(N);
        for (int i = 0; i < N; i++)
            cin >> B[i];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        if (N == 1)
            cout << A[0] + B[0] << endl;
        else{
            set<ll> C = {A[0], A[0] + B[0], A[0] + B[1], A[0] + B[0] + B[1]};
            set<ll> D = {A[N -1], A[N -1] + B[N -1], A[N -1] + B[N -2], A[N -1] + B[N -1] + B[N -2]};
            vector<ll> I;
            set_intersection(C.begin(), C.end(), D.begin(), D.end(),
                        std :: inserter(I, I.begin()) );
            if (I.size() == 0)
                cout << -1 << endl;
            else
                cout << *(I.begin()) << endl;
        }
    }


    return 0;
}
