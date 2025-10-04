// https://leetcode.cn/problems/subsets/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int>& nums, vector<int> tmp, int cur){
        if(cur == nums.size()){
            res.push_back(tmp);
            return;
        }
        dfs(res,nums,tmp,cur + 1);
        tmp.push_back(nums[cur]);
        dfs(res,nums,tmp,cur + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, nums, tmp,0);
        return res;
    }
};