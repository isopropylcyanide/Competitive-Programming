#include<bits/stdc++.h>

template<typename T> void print_queue(T& qq) {
    T q = qq;
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

ostream & operator<<(ostream &c, vector<int> &vec){
    for (auto it: vec){
        c << it << " -> ";
    }
    c << std::endl;
    return c;
}
 

class MedianFinder {
public:
    /** initialize your data structure here. */

    std::priority_queue<int, std::vector<int>, std::greater<int>> rhsMinQueue;
    std::priority_queue<int, std::vector<int>, std::less<int>> lhsMaxQueue;
    vector<int> temp;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        std::cout << "Pushing item " << num << std::endl;
        temp.push_back(num);
    
        //always add in rhs queue blindly
        rhsMinQueue.push(num);
        int lhs = lhsMaxQueue.size();
        int rhs = rhsMinQueue.size();

        //if there's a mismatch of 2 or min is lesser, rebalance
        int rhsMin = rhsMinQueue.top();

        if (rhs == lhs + 2 || ((rhs == lhs + 1 and lhs != 0 ) && rhsMin < lhsMaxQueue.top()) ){
            //move from rhs to lhs
            std::cout << "\n Rebalance \n";
            rhsMinQueue.pop();
            lhsMaxQueue.push(rhsMin);
        }
        else if ((rhs == lhs) && rhsMin < lhsMaxQueue.top()){
            //swap lhs and rhs
            std::cout << "Swapping tops" << std::endl;
            int lhs = lhsMaxQueue.top();
            int rhs = rhsMinQueue.top();
            lhsMaxQueue.pop();
            rhsMinQueue.pop();
            lhsMaxQueue.push(rhs);
            rhsMinQueue.push(lhs);
        }

        std::cout << "LHS ";
        print_queue(lhsMaxQueue);
        std::cout << "RHS ";
        print_queue(rhsMinQueue);
        std::cout << "Current median is : " << findMedian() << std::endl << std::endl;
        std::cout << "Normal median is : " << findMedianConventional() << std::endl << std::endl;
    }
    
    double findMedianConventional() {
        std::sort(temp.begin(), temp.end());
        cout << "\nNormal vector: " << temp;
        int n = temp.size();
        if (n % 2 == 0){
            return (temp[n/2] * 1.0 + temp[n/2 -1] * 1.0)/2.0;
        }
        return temp[n/2];
    }

    double findMedian() {
        int lhs = lhsMaxQueue.size();
        int rhs = rhsMinQueue.size();

        if (lhs == rhs){
            if (lhs == 0){
                perror("Median is undefined with a non partitionable set");
            }
            int leftMax = lhsMaxQueue.top();
            int rightMin = rhsMinQueue.top();
            return ((leftMax + rightMin) * 1.0) / 2.0;
        }
        else{
            if (lhs > rhs){
                return lhsMaxQueue.top();
            }
            return rhsMinQueue.top();
        }

        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    MedianFinder finder;
    // finder.addNum(5);
    // finder.addNum(3);
    // finder.addNum(7);
    // finder.addNum(10);
    // finder.addNum(25);
    // finder.addNum(20);
    // finder.addNum(15);

    finder.addNum(-1);
    finder.addNum(-2);
    finder.addNum(-3);
    finder.addNum(-4);
    finder.addNum(-5);
}