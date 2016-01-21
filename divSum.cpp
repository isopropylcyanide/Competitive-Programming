#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class AdvancedArithmetic{
    public:
          virtual int divisorSum(int n)=0;
};

class Calculator : public AdvancedArithmetic{
    set<int> myDiv;

    void getDivisors(int &n){
        for (int i = 1; i * i <= n; i++){
            if (n % i == 0)
                myDiv.insert(i);
            if (n % (n / i) == 0)
                myDiv.insert(n / i);
        }
    }

public:
    int divisorSum(int n){
        getDivisors(n);
        return accumulate(myDiv.begin(), myDiv.end(), 0);
    }

};

int main(){
    int n;
    cin>>n;
    AdvancedArithmetic *myCalculator=new Calculator();
    int sum=myCalculator->divisorSum(n);
    cout<<"I implemented: AdvancedArithmetic\n"<<sum;
    return 0;
}
