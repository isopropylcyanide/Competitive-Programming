#include<bits/stdc++.h>

ostream& operator<< (ostream& os, vector<int> & arr){
    // overload ostream operator for easy output
    for(auto elem : arr)
        os<<elem<<" ";
    os << endl;
    return os;
}

ostream& operator<< (ostream& os, deque<int> & arr){
    // overload ostream operator for easy output
    for(auto elem : arr)
        os<<elem<<" ";
    os << endl;
    return os;
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> dequeue;
        vector<int> out;
        int n = nums.size();
        if (k < 1 || k > n){
            return {};
        }
        //current window: 0 to K -1..only keep useful indices
        for (int i = 0; i < k; i++){
            int elemNew = nums[i];
            //while values repr by indices are less than this value, remove as they are useless
            while (dequeue.size() != 0 && nums[dequeue.back()] <= elemNew){
                // std::cout << "\nPopping back index " << dequeue.back() << " as " << nums[dequeue.back()] << " <= " << i << " : " << nums[i];
                dequeue.pop_back();
            }
             dequeue.push_back(i);
        }
        // std::cout << "\n Initial dequeue \n" << dequeue << endl;
        out.push_back(nums[dequeue.front()]);
        // std::cout << "now " << out;
        
        //at the end remove all indices that should not be a part of this window.
        for (int i = k; i < n; i++){
            // boundary is now [i - k + 1 to i] closed
            // before adding new elem..cleanup : remove front if < i - k + 1 and while back elem are lesser
            // std::cout << "\n\n Trying to insert i : " << i << " : " << nums[i];
            // std::cout << "\n Current dequeue: " << dequeue << endl;
            if (dequeue.front() < (i - k + 1)){
                // std::cout << "\nUnfortunately popping front index " << dequeue.front() << " as " << dequeue.front() << " is not between " << (i - k + 1) << " to  " << i;
                dequeue.pop_front();
            }
            int elemNew = nums[i];
            while (dequeue.size() != 0 && nums[dequeue.back()] <= elemNew){
                // std::cout << "\nPopping back index " << dequeue.back() << " as " << nums[dequeue.back()] << " <= " << i << " : " << nums[i];
                dequeue.pop_back();
            }
            dequeue.push_back(i);
            out.push_back(nums[dequeue.front()]);
            // std::cout << "Out looks like " << out;
            // std::cout << "Dequeue looks like " << dequeue;
        }
        return out;
    }

    
};

int main(){
    Solution s;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    // vector<int> nums = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    // std::cout << "\n ----------------- \n";
    for (auto a : s.maxSlidingWindow(nums, 3)){
        std::cout << a << std::endl;
    }
}