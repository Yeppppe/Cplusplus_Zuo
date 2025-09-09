// https://leetcode.cn/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;

//! 查询的本质是找到第一个大于等于目标值的位置
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = n;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] >= target){             //! 如果使用的是<= target的判断逻辑，实际上找的是最后一个小于等于或等于目标值的位置
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};