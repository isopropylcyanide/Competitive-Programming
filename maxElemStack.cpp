#include<bits/stdc++.h>
using namespace std;
stack<int> s;
stack<int> maxStack;

int main(){
    int n, query, elem;
    cin >> n;
    maxStack.push(-1);

    while(n--){
        cin >> query;
        if (query == 1){
            // push to Stack;
            cin >> elem;
            if (elem >= maxStack.top())
                maxStack.push(elem);
            s.push(elem);
        }
        else if (query == 2){
            // pop from stack
            if (s.top() == maxStack.top())
                maxStack.pop();
            s.pop();
        }
        else if (query == 3){
            cout << maxStack.top() <<endl;
        }
    }

    return 0;
}
