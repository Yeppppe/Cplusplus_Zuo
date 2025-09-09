// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int first = -1, last = -1;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] == target){
                first = mid;
                r = mid - 1;
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        l = 0;
        r = n - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] == target){
                last = mid;
                l = mid + 1;
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return {first, last};
    }
};