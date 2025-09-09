// https://leetcode.cn/problems/search-in-rotated-sorted-array/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;

class Solution {
// 将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。
// 此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环. 
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) return nums[0] == target ? 0 : -1;
        int l = 0;
        int r = n - 1;
        int mid;
        while(l <= r){
            mid = (l + r)/2;
            if(nums[mid] == target) return mid;
            //! 0 -> mid 有序
            if(nums[0] <= nums[mid]){           //! 注意这个是小于等于，说明mid左边都有序
                if(nums[mid] > target && nums[0] <= target){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && nums[n - 1] >= target){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};