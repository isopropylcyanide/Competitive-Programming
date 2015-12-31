#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class BIT{
    int BIT_size;
    vector <int> b;

    public:
        explicit BIT(const vector<int> &a){
            BIT_size = a.size() + 1;
            b.resize(BIT_size);
            b[0] = 0;

            for (int i = 1; i < BIT_size; i++)
                update(i,a[i -1]);
        }

        void display(){
            for (auto a1: b)
                    cout << " -> "<<a1;
                cout << endl;
        }

        ~BIT(){
            b.erase(b.begin(),b.end());
        }

        void update(int i, int value){
            while (i < BIT_size){
                b[i] += value;
                i += (i & -i);
            }
        }

        int sum(int i){
            // Sum from 1 to a
            int res = 0;
            while (i){
                res += b[i];
                i -= (i & -i) ;
            }
            return res;
        }

        int sum(int a, int b){
            return sum(b) - (a -1);
        }

        void query(){
            int choice = 1,x,y;
            int *arr;
            while(choice){
                cout << "\nEnter choice(1-find sum)/2(Update): ";
                cin >> choice;

                if (choice == 1){
                    // BIT find sum
                    cout <<"\n Enter space sep range: ";
                    cin >> x >> y;
                    cout << sum(x,y)<<endl;
                }
                else if (choice == 2){
                    // BIT update
                    cout <<"\n Enter pos and value: ";
                    cin >> x >> y;
                    update(x ,y - arr[x - 1]);
                    arr[x -1] = y;
                }
                else choice = 0;
            }   
        }

 };


void dfs_children(vector< vector<int> > & graph,int & i, vector<bool> & visited,set<int> &reachable){
    if (graph[i].size() == 0 || visited[i] == true)
        return;
    visited[i] = true;

    for (auto child : graph[i]){
        if (visited[child] == false){
            reachable.insert(child);
            dfs_children(graph, child, visited, reachable);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);

    vector<int> arr = {1,4,6,10,12,16,3,4};
    int N, T, temp, x, y;
    BIT b(arr);

    cin >> N >> T;
    vector< vector<int> > graph(N +1);
    set<int> reachable;

    for (int i = 1; i < N; i++){
        cin >> x >> y;
        graph[x].push_back(y);
    }

    int count_pair = 0;

    for (int i = 1; i <= N; i++){
        vector <bool> visited(N +1,false);
        reachable.clear();
        dfs_children(graph, i, visited, reachable);
        for (auto b : reachable){
            if (abs(b - i) <= T){
                // cout << "\n("<<i<<","<<b<<")";
                count_pair += 1;
            }
        }
    }

    cout <<count_pair<<endl;

    return 0;
}

