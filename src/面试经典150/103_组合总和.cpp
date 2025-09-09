// https://leetcode.cn/problems/combination-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates, int target, int cur, int sum){
        if(sum >= target){
            if(sum == target){
                ans.push_back(tmp);
            }
            return;
        }
        for(int i = cur; i < candidates.size(); i++){
            tmp.push_back(candidates[i]);
            dfs(candidates,target,i,sum+candidates[i]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target,0,0);
        return ans;
    }
};