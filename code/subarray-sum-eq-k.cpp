#include<bits/stdc++.h>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sumSoFar = 0;
        int totalCount = 0;
        std::unordered_map<int, int> prefix_sum_seen_count;

        for (int i = 0; i < nums.size(); i++){
            sumSoFar += nums[i];
            if (sumSoFar == k){
                //std::cout << "Naturally equal";
                totalCount += 1;
            }
            if (prefix_sum_seen_count.find(sumSoFar - k) != prefix_sum_seen_count.end()){
                //found an entry
                totalCount += prefix_sum_seen_count[sumSoFar - k];
            }
            if (prefix_sum_seen_count.find(sumSoFar) != prefix_sum_seen_count.end()){
                //exists
                prefix_sum_seen_count[sumSoFar] += 1;
            }
            else{
                prefix_sum_seen_count[sumSoFar] = 1;
            }
        }
        return totalCount;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    auto t1 = chrono::high_resolution_clock::now();
    vector<int> v = {4, 6, 0, 3, -9, -11, 7};
    // vector<int> v = {1,1,1};
    
    Solution solution;
    std::cout << solution.subarraySum(v, 0) << std::endl;
    //std::cout << solution.subarraySum(v, 2) << std::endl;

    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<int64_t,nano> elapsed = t2 - t1; //if you want milli
    std::cout << "Algorithm Runtime is: " << elapsed.count() / 1000000 << " ms.";
}
