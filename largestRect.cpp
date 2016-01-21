#include<bits/stdc++.h>
using namespace std;

stack<int> s;

void display(){
    cout <<"\n STACK: ";
    stack<int> newS(s);
    while (!newS.empty()){
        cout << newS.top() << " ";
        newS.pop();
    }
    cout << endl;
}

int main(){
    int n, temp, i = 0;
    int indexMin, indexMax, maxArea, minHeight;
    cin >> n;

    vector<int> ht;
    for (int i = 0; i < n; i++){
        cin >> temp;
        ht.push_back(temp);
    }

    while (i < n){
        if (s.empty() || ht[i] > ht[s.top()])
            s.push(i++);
        else {
            temp = s.top();
            s.pop();
            int areaWithTop = ht[temp] * (s.empty() ? i : i - s.top() - 1);

            if (maxArea < areaWithTop)
                maxArea = areaWithTop;
        }
    }

    while (! s.empty()){
        temp = s.top();
        s.pop();
        int areaWithTop = ht[temp] * (s.empty() ? i : i - s.top() - 1);

        if (maxArea < areaWithTop)
            maxArea = areaWithTop;
    }

    cout << maxArea <<endl;
}










// END
