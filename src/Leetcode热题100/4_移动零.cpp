// https://leetcode.cn/problems/move-zeroes/description/?envType=study-plan-v2&envId=top-100-liked

#include <vector>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        while(r < n){
            if(nums[r]){
                swap(nums[l], nums[r]);   //! swap被C++标准库已经实现，底层使用了移动语义
                l++;
            }
            r++;
        }
    }
};