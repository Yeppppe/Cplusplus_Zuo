// https://leetcode.cn/problems/find-peak-element/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n -1;
        int mid;
        while(l < r){
            mid = (l + r)/2;
            if(nums[mid] > nums[mid + 1]){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};