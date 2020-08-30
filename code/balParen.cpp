#include<bits/stdc++.h>
using namespace std;

map<char, char> balPairs;
vector<char> openPair = {'{','(','['};
vector<char> closePair = {'}',')',']'};
stack<char> s;

void display(){
    cout <<"\n STACK: ";
    stack<char> newS(s);
    while (!newS.empty()){
        cout << newS.top() << " ";
        newS.pop();
    }
    cout << endl;
}

int main(){
    int n; string line;
    cin >> n;
    bool unbalanced;

    for (int i = 0; i < 3; i++)
        balPairs.insert(make_pair(closePair[i], openPair[i]));

    while(n--){
        cin >> line;
        for (auto a: line){
            unbalanced = false;

            if (find(openPair.begin(), openPair.end(), a) == openPair.end()){
                // elem is coming from closePair
                if (s.size() == 0){
                    unbalanced = true;
                    break;
                }
                else if (s.top() == balPairs[a])
                    s.pop();
                else{
                    unbalanced = true;
                    break;
                }
            }
            else{
                // elem is coming from an open list
                s.push(a);
            }
        }
        if (unbalanced || (s.size() > 0))
            cout <<"NO\n";
        else cout <<"YES\n";
        while(!s.empty())
            s.pop();
    }

    return 0;
}
