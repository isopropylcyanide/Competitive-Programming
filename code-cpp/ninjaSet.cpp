#include <bits/stdc++.h>
using namespace std;
int N;

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, T;
    cin >> T;
    for (int t = 1; t <= T; t++){

        map<int, bool> nodeA, nodeB;
        cin >> N;
        for (int i = 0; i < N; i++){
            cin >> a >> b;

            if (nodeA.find(a) != nodeA.end())
                nodeB.insert(make_pair(b, false));

            else if (nodeB.find(a) != nodeB.end()){
                nodeA.insert(make_pair(b, false));
            }
            else if (nodeB.find(b) != nodeB.end())
                nodeA.insert(make_pair(a, false));
            else{
                nodeA.insert(make_pair(a, false));
                nodeB.insert(make_pair(b, false));
            }

        }

        cout << "Case "<< t <<": " << max(nodeA.size(), nodeB.size()) << endl;
    }


    return 0;
}
