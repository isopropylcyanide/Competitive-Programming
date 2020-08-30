#include<bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;
stack <llu> s;

void display(){
    cout <<"\n STACK: ";
    stack<llu> newS(s);
    while (!newS.empty()){
        cout << newS.top() << " ";
        newS.pop();
    }
    cout << endl;
}

int main(){
    llu n, temp, i;
    cin >> n;
    vector<llu> pest;
    llu maxDays = 0, currentDays;

    for (int i = 0; i < n; i++){
        cin >> temp;
        pest.push_back(temp);
    }

    for (int i = n - 1; i >= 0; i--){
        if (s.empty() || (pest[i] >= s.top()))
            s.push(pest[i]);

        else {
            currentDays = 0;
            while(!s.empty() && pest[i] < s.top()){
                currentDays += 1;
                s.pop();
            }
            if (currentDays > maxDays)
                maxDays = currentDays;
            s.push(pest[i]);
        }
    }
    cout << maxDays <<endl;
    return 0;
}

// END
