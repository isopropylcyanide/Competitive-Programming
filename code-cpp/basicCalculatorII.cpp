#include <bits/stdc++.h>

int calculate(string s) {
    stack<int> stack;
    int number = 0;
    int n = s.size();
    int result = 0;  // For the on-going result
    int sign = 1;    // 1 means positive, -1 means negative

    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (isdigit(ch)) {
            number = 10 * number + (ch - '0');

        } else if (ch == '+') {
            // Evaluate the expression to the left, with result, sign, number
            result += sign * number;
            sign = 1;
            number = 0;

        } else if (ch == '-') {
            result += sign * number;
            sign = -1;
            number = 0;

        } else if (ch == '(') {
            // Push the result and sign on to the stack, for later
            // We push the result first, then sign
            stack.push(result);
            stack.push(sign);

            // Reset number and result, as if new evaluation begins for the new sub-expression
            sign = 1;
            result = 0;

        } else if (ch == ')') {
            // Evaluate the expression to the left
            // with result, sign and number
            result += sign * number;

            // ')' marks end of expression within a set of parenthesis
            // Its result is multiplied with sign on top of stack
            // as stack.pop() is the sign before the parenthesis
            result *= stack.top();
            stack.pop();

            // Then add to the next number on the top.
            // as stack.pop() is the result calculated before this parenthesis
            // (number on stack) + (sign on stack * (result from parenthesis))
            result *= stack.top();
            stack.pop();

            // Reset the number
            number = 0;
        }
    }
    return result + (sign * number);
}

int main() {
    std::cout << calculate("1 + 1") << endl;
    std::cout << calculate(" 2-1 + 2 ") << endl;
    std::cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    return 0;
}
