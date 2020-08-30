#include <bits/stdc++.h>
#include <iostream>
#define MAX  500005
#define inf 0x7fffffff
using namespace std;

typedef long long int ll;

//Q Queries. Increment A by K and find the absolute sum
ll N, Q, temp,K;

void solve(vector<ll> & A, const ll & N){

    ll balls = 0, myGCD;
    // numbers have to be in non decreasing order firstly

    ll mark = A[0];
    for (int i = 1; i < N; i++)
        if (A[i] < mark){
            balls += mark - A[i];
            A[i] = mark;
        }

    while(true) {
        cout <<"\n BALL : "<<balls <<" : ";
        for (auto a : A) cout <<" " << a;

        myGCD = A[0];
        for (int i = 1; i < N; i++)
            myGCD = __gcd(myGCD,A[i]);

        if (myGCD > 1)break;
        else{
            balls += 1;
            transform(A.begin(), A.end(), A.begin(), bind2nd(plus<ll>(),1) );
        }
        cout << " : "<< myGCD;
    }

    cout <<"\n\nballs: "<<balls<<endl;

}

int main(){
    ios::sync_with_stdio(false);

    int testcases;
    cin >> testcases;

    while(testcases --){
        
        cin >> N;
        vector<ll> A(N);

        for (ll i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N);
   }

    return 0;
}