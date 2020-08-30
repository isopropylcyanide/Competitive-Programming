#include <bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream &c, vector<vector<int>> vec){
    int N = vec.size();
    if (N != 0){
        int M = vec[0].size();
        for (int i = 0; i < N; i++){
            c << "_ ";
        }
        c << endl;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                c << vec[i][j] << "|" ;
            }
            c << endl;
        }
    }
    c << endl;
    return c;
}

bool outBound(int x, int y, int N, int M){
    return (x < 0 || x >= M) || (y < 0 || y >= N);
}

int xs[4] = {-1, 0, 0, 1};
int ys[4] = {0, 1, -1, 0};

typedef struct crawler{
    int distance;
    int x, y;
    crawler(int x, int y, int d): x(x), y(y), distance(d){}
} crawler;

ostream& operator<<(ostream &c, crawler& l){
    c << " At (" << l.x << "," << l.y << ") with [" << l.distance << "] units ";
    return c;
}

void bfs(int i, int j, int N, int M, vector <vector <int>> &vec){
    queue<crawler> crawlers;
    crawlers.push(crawler(i, j, 0));

    bool found = false;
    int dist = 0;

    while (!found && !crawlers.empty()){
        int len = crawlers.size();
        dist++;
        while(len --){
            crawler top = crawlers.front();
            crawlers.pop();
            for(int it = 0; it < 4; it++){
                int newX = top.x + xs[it];
                int newY = top.y + ys[it];
                if(outBound(newX, newY, N, M)){
                    continue;
                }
                if(vec[newX][newY] == 0){
                    found = true;
                    break;
                }
                else {
                    crawlers.push(crawler(newX, newY, dist + 1));
                }
            }
        }
        if(found){
            break;
        }
    }
    vec[i][j] = dist;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int N = matrix.size();
    int M = matrix[0].size();
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (matrix[i][j] != 0){
                bfs(i, j, N, M, matrix);
            }
        }
    }
    return matrix;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,  M;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int> (M, 0));

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> matrix[i][j];
        }
    }
    cout << updateMatrix(matrix);
    return 0;
}
