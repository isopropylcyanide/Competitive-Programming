#include <bits/stdc++.h>
using namespace std;

// Program for large multiplication
bool negA = false;
bool negB = false;

string addStr(string &a, string &b){
    //Add two strings
    if (a == "0")
        return b;
    if (b == "0")
        return a;

    string res = "";
    int i = a.size() -1, j = b.size() -1, carry = 0;

    while (true){
        if (i < 0 && j < 0)
            break;
        int dA = i < 0 ? 0 : a[i--] - '0';
        int dB = j < 0 ? 0 : b[j--] - '0';
        int sum = dA  + dB  + carry;
        carry = sum / 10;
        res += to_string(sum % 10);
    }

    if (carry != 0)
        res += to_string(carry);

    reverse(res.begin(), res.end());
    return res;
}

string multiplyStr(string &a, string &b){
    // Produce multiplication of two strings in TC: O(m * n)
    // Multiply b * a
    if (a == "0" || b == "0")
        return "0";

    string ans = "0", prod = "";
    int padZero = 0;

    for (int i = b.size() -1; i >= 0; i--){
        padZero = b.size() - 1 - i;
        int carry = 0;

        for(int j = a.size()-1 ; j >= 0; j--){
            int mul = (b[i] - '0') * (a[j] - '0') + carry;
            prod += to_string(mul % 10);
            carry = mul / 10;
        }

        if (carry != 0)
            prod += to_string(carry);

        prod = string(padZero,'0') + prod;
        reverse(prod.begin(), prod.end());
        ans = addStr(prod, ans);
        prod = "";
    }
    if ((negA ^ negB) == true)
        return "-" + ans;
    return ans;
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int testcases;
    string a, b;

    cin >> testcases;
    while (testcases--){
        cin >> a;
        cin >> b;
        negA = a[0] == '-' ? true : false;
        negB = b[0] == '-' ? true : false;
        if (negA)
            a.erase(a.begin());
        if (negB)
            b.erase(b.begin());

        cout << multiplyStr(a, b) << endl;
    }



    return 0;
}
