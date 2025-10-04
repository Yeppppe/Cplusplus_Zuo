// https://leetcode.cn/problems/permutations/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& nums, int first, int end){
        if(first == end){
            res.push_back(nums);
            res;
        }

        for(int i = first; i < end; i++){
            swap(nums[first], nums[i]);
            dfs(res, nums, first + 1, end);
            swap(nums[first], nums[i]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, nums, 0, nums.size());
        return res;
    }
};