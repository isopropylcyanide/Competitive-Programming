#include <bits/stdc++.h>
using namespace std;

ostream &operator<<(ostream &c, stack<char> &s){
    stack<char> p = s;
    while (!p.empty()){
        cout <<" " << p.top() << " -> ";
        p.pop();
    }
    return c;
}

int isValid(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<char>s;
    char popped;

    for (int i = 0; i < A.size(); i++){
        cout << "i: "<<i <<" -> "<<A[i] << endl;

        if (A[i] == '{' || A[i] == '(' || A[i] == '[')
            s.push(A[i]);

        else if (A[i] == ')'){
            if (s.empty() || s.top() != '(')
                return 0;
            else s.pop();
        }

        else if (A[i] == ']'){
            if (s.empty() || s.top() != '[')
                return 0;
            else s.pop();
        }

        else if (A[i] == '}'){
            if (s.empty() || s.top() != '{')
                return 0;
            else s.pop();
        }


        cout << "\nStack: " << s << endl;
    }
    return s.size() == 0 ? 1 : 0;
}

int main(){
    cout << isValid("()[]{}") << endl;
    return 0;
}













//
