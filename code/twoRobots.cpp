#include <bits/stdc++.h>
using namespace std;

int N, testcases, M, a, b;
vector< pair<int, int> > T;
vector< vector< vector<int> > > dp;

int robotSum(int i, int sum, int rA, int rB){
    // cout << "\ni: "<<i<<" Sum: "<<sum<<" rA: "<<rA<<" rB: "<<rB << endl;
    if (i == N)
        return sum;

    int sumA = abs(T[i].first - T[i].second) + abs(T[i].first - rA);
    int sumB;
    if (rB == 0)
        sumB = abs(T[i].first - T[i].second);
    else
        sumB = abs(T[i].first - T[i].second) + abs(T[i].first - rB);

    // cout <<" Sum Robot A : "<<sumA << endl;
    // cout <<" Sum Robot B : "<<sumB << endl;

    int minA = robotSum(i + 1 , sum + sumA, T[i].second, rB);
    int minB = robotSum(i + 1, sum + sumB, rA, T[i].second);

    return (minA < minB)?minA : minB;
}

int robotSumDP(int i, int sum, int rA, int rB){
    // cout << "\ni: "<<i<<" Sum: "<<sum<<" rA: "<<rA<<" rB: "<<rB << endl;
    if (i == N)
        return sum;

    if (dp[i][rA][rB] != -1)
        return dp[i][rA][rB];

    int sumA = abs(T[i].first - T[i].second) + abs(T[i].first - rA);
    int sumB;
    if (rB == 0)
        sumB = abs(T[i].first - T[i].second);
    else
        sumB = abs(T[i].first - T[i].second) + abs(T[i].first - rB);


    dp[i][T[i].second][rB] = robotSumDP(i + 1 , sum + sumA, T[i].second, rB);
    dp[i][rA][T[i].second] = robotSumDP(i + 1, sum + sumB, rA, T[i].second);

    return dp[i][T[i].second][rB] < dp[i][rA][T[i].second] ? dp[i][T[i].second][rB] :  dp[i][rA][T[i].second];
}



int minimumDistance(){
    // Find minimum distance two robots would have to travel
    dp.clear();
    dp.resize(N, vector< vector< int> >(M * 2, vector<int>(M * 2, 0)));
    return robotSum(1, abs(T[0].first - T[0].second), T[0].second, 0);
}


int main(){
    ios :: sync_with_stdio(false);
    cin >> testcases;

    while (testcases --){
        cin >> M >> N;
        T.resize(0);

        for (int i = 0; i < N; i++){
            cin >> a >> b;
            T.push_back(make_pair(a, b));
        }
        cout << minimumDistance() << endl;
    }
    return 0;
}
