#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Bipartite matching

int N, M, K,temp,x,y;
vector< pair<int, int> > bikes;
vector< pair<int, int> > bikers;
int dist[255][255];

int get_square_dist(const pair<int, int>&a, const pair<int, int> &b){
        return (b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second);
}

int main(){
        ios::sync_with_stdio(false);

        cin >> N >> M >> K;
        for (int i = 0; i < N; i++) {
                cin >> x >> y;
                bikers.push_back(make_pair(x,y));
        }

        for (int i = 0; i < M; i++) {
                cin >> x >> y;
                bikes.push_back(make_pair(x,y));
        }

        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        dist[i][j] = get_square_dist(bikers[i], bikes[j]);
                }
        }

        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++)
                        printf("\nDIST biker: %d to bike: %d : %d",i+1, j+1, dist[i][j]);
        }
        return 0;
}
