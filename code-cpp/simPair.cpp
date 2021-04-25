#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int N, T, temp, x, y, root;

vector< vector<int> > graph;
set<int> reachable;
vector<int> degree;
int count_pair =0;

    class BIT {
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

        explicit BIT(int n){
                BIT_size = n + 1;
                b.resize(BIT_size,0);

        }
        void display(){
                for (auto a1 : b)
                        cout << " -> "<<a1;
                cout << endl;
        }

        ~BIT(){
                b.erase(b.begin(),b.end());
        }

        int sum_range(int i, int j){
                int sum = 0;
                while(j>0)
                {
                        sum+=b[j];
                        j -= (j & (j* -1));
                }
                i--;
                while(i>0)
                {
                        sum-=b[i];
                        i -= (i & (i* -1));
                }
                return sum;
        }
        void update(int i, int value){
                while (i < BIT_size) {
                        b[i] += value;
                        i += (i & -i);
                }
                // display();
        }

        int sum(int i){
                // Sum from 1 to a
                int res = 0;
                while (i) {
                        res += b[i];
                        i -= (i & -i);
                }
                return res;
        }

        int sum(int a, int b){
                // Sum from a to b
                return sum(b) - (a -1);
        }

        void query(){
                int choice = 1,x,y;
                int *arr;
                while(choice) {
                        cout << "\nEnter choice(1-find sum)/2(Update): ";
                        cin >> choice;

                        if (choice == 1) {
                                // BIT find sum
                                cout <<"\n Enter space sep range: ";
                                cin >> x >> y;
                                cout << sum(x,y)<<endl;
                        }
                        else if (choice == 2) {
                                // BIT update
                                cout <<"\n Enter pos and value: ";
                                cin >> x >> y;
                                update(x,y - arr[x - 1]);
                                arr[x -1] = y;
                        }
                        else choice = 0;
                }
        }

        };



void dfs(int &node, BIT & b){

        count_pair += b.sum_range(max(1,node - T), min(N, node + T));
        b.update(node, 1);

        for (auto child : graph[node])
                dfs(child, b);

        b.update(node, -1);
}



int main(){
        ios::sync_with_stdio(false);
        cin >> N >> T;

        graph.resize(N +1);
        degree.resize(N +1, 0);
        BIT bit(N);

        for (int i = 1; i < N; i++) {
                cin >> x >> y;
                graph[x].push_back(y);
                degree[y] += 1;
        }

        for (int i = 1; i <= N; i++) {
                if (degree[i] == 0) {
                        root = i;
                        break;
                }
        }

        dfs(root, bit);

        cout <<count_pair<<endl;

        return 0;
}
