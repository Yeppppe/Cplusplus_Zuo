// https://leetcode.cn/problems/permutations/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<bool> vis;
    void dfs(vector<int>& nums){
        if(tmp.size() == nums.size()){
            ans.push_back(tmp);
        }

        for(int i = 0; i < nums.size(); i++){
            if(vis[i] == false){
                tmp.push_back(nums[i]);
                vis[i] = true;
                dfs(nums);
                tmp.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vis.resize(nums.size());
        dfs(nums);
        return ans;
    }
};