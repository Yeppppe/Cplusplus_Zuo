// https://leetcode.cn/problems/3sum/description/?envType=study-plan-v2&envId=top-100-liked
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if( i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                if(nums[l] + nums[r] + nums[i] > 0){
                    r--;
                }
                else if(nums[l] + nums[r] + nums[i] < 0){
                    l++;
                }
                else{
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l + 1]) l++;
                    while(l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};