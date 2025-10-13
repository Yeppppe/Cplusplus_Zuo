// https://leetcode.cn/problems/n-queens/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <string>
using namespace std
class Solution {
public:
    bool issafe(vector<int>& path, int cur){
        for(int i = 0; i < path.size(); i++){
            if( path[i] == cur || abs( i - (int)path.size() ) == abs( path[i] - cur ) ) return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& path, int n){
        if(path.size() == n){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < n; i++){
            if(issafe(path, i)){
                path.push_back(i);
                dfs(ans, path, n);
                path.pop_back();
            }
        }
    }

    void output(vector<vector<string>>& res, vector<vector<int>>& ans, int n){
        for(auto vec : ans){
            vector<string> one_case;
            for(int i = 0; i < n; i++){
                string tmp;
                for(int j = 0; j < n; j++){
                    if(j == vec[i]){
                        tmp.push_back('Q');
                    }
                    else{
                        tmp.push_back('.');
                    }t
                }
                one_case.push_back(tmp);
            }
            res.push_back(one_case);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> ans;
        vector<vector<string>> res;
        vector<int> path;
        dfs(ans, path, n);
        output(res, ans, n);
        return res;
    }
};