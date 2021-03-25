#include <bits/stdc++.h>

//Solves expression value when given value contains no parenthesis
int calculate(string s) {
    int n = s.length();
    if (n == 0) {
        return 0;
    }
    stack<int> digitStack;
    int number = 0;
    char operation = '+';

    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (isdigit(ch)) {
            number = (number * 10) + (ch - '0');
        }
        if ((!isdigit(ch) && !iswspace(ch)) || i == n - 1) {
            if (operation == '-') {
                digitStack.push(-number);

            } else if (operation == '+') {
                digitStack.push(number);

            } else if (operation == '*') {
                int stackTop = digitStack.top();
                digitStack.pop();
                digitStack.push(stackTop * number);

            } else if (operation == '/') {
                int stackTop = digitStack.top();
                digitStack.pop();
                digitStack.push(stackTop / number);
            }
            operation = ch;
            //reset number as we have seen a digit
            number = 0;
        }
    }
    int result = 0;
    while (digitStack.size() != 0) {
        result += digitStack.top();
        digitStack.pop();
    }
    return result;
}

int main() {
    std::cout << calculate("1 + 1") << endl;
    std::cout << calculate(" 2-1 + 2 ") << endl;
    return 0;
}
