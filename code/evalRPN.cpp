#include <bits/stdc++.h>
using namespace std;

int op(int a, int b, string &op){
    if (op == "+")      return a + b;
    else if (op == "-") return a - b;
    else if (op == "*") return a *b;
    else if (op == "/") return a/b;
    return 0;
}

int evalRPN(vector<string> &A) {
    const size_t N = A.size();
    int a, b;
    stack<int> st;

    for (size_t j = 0; j < N; j++) {
        if (A[j] == "+" || A[j] == "-" || A[j] == "*" || A[j] == "/"){
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(op(a, b, A[j]));
        }
        else st.push(stoi(A[j]));
    }
    return st.top();
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

int main(){
    vector<string> c = {"4", "13", "5", "/", "+"};
    cout << evalRPN(c);
}
