#include <iostream>
#include <stack>
#include <set>

using namespace std;

/**
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions )
 * so that the resulting parentheses string is valid and return any valid string.
 */

ostream &operator<<(ostream &c, set<int> s) {
    for (auto k : s) {
        c << k << " -> ";
    }
    c << endl;
    return c;
}

typedef struct entry {
    int index;
    char val;
} entry;

string minRemoveToMakeValid(string s) {
    stack<entry> potentialIgnoreIdx;
    set<int> definitelyIgnoreIdx;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            //if tos is empty, this is definitely out of place
            if (potentialIgnoreIdx.empty()) {
                definitelyIgnoreIdx.insert(i);

            } else if (potentialIgnoreIdx.top().val == '(') {
                //there's a () balance and we can ignore both these
                potentialIgnoreIdx.pop();

            } else {
                //situation of x)))<-)
                definitelyIgnoreIdx.insert(i);
            }
        } else if (s[i] == '(') {
            //potential imbalance, using marker value to indicate (avoids struct)
            potentialIgnoreIdx.push(entry{i, '('});
        }
    }
    //anything remaining in potential ignore needs to be added to definite ignore
    while (!potentialIgnoreIdx.empty()) {
        definitelyIgnoreIdx.insert(potentialIgnoreIdx.top().index);
        potentialIgnoreIdx.pop();
    }
//    std::cout << "\n Definitely ignore: " << definitelyIgnoreIdx << endl;
    string ans;
    for (int i = 0; i < s.length(); i++) {
        if (definitelyIgnoreIdx.find(i) == definitelyIgnoreIdx.end()) {
            //not ignored
            ans += s[i];
        }
    }
    return ans;
}

int main() {
    std::cout << minRemoveToMakeValid("lee(t(c)o)de))") << endl;
    std::cout << minRemoveToMakeValid(")))(()((") << endl;
}