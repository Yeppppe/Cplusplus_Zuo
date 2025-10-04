// https://leetcode.cn/problems/combination-sum/description/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& candidates, vector<int> tmp,int cur_index, int cur_num, int target){
        if(cur_index == candidates.size()){
            return;
        }
        if(cur_num >= target){
            if(cur_num == target)
                res.push_back(tmp);
            return;
        }
        tmp.push_back(candidates[cur_index]);
        dfs(res,candidates,tmp,cur_index, cur_num + candidates[cur_index], target);

        tmp.pop_back();
        dfs(res,candidates,tmp,cur_index + 1, cur_num, target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, candidates, tmp, 0, 0, target);
        return res;
    }
};

