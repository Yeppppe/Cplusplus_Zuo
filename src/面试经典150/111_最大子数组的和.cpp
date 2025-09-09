// https://leetcode.cn/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int maxans = nums[0];
        for(auto n : nums){
            pre = max(n, pre + n);
            maxans = max(maxans, pre);
        }
        return maxans;
    }
};