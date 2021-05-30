#include <iostream>
#include <string>
#include <map>

int lengthOfLongestSubstringKDistinct(std::string nums, int k) {
    std::map<int, int> numCount;
    int l = 0, ans = 0;
    for (int r = 0; r < nums.size(); r++) {
        if (numCount[nums[r]] == 0) {
            k = k - 1;
        }
        numCount[nums[r]] += 1;
        while (k < 0) {
            numCount[nums[l]] = numCount[nums[l]] - 1;
            if (numCount[nums[l]] == 0) {
                k += 1;
            }
            l += 1;
        }
        ans = std::max(ans, (r - (l - 1)));
    }
    return ans;
}


int main() {
    std::cout << lengthOfLongestSubstringKDistinct("eceba", 2) << std::endl;
    return 0;
}
