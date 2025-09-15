// https://leetcode.cn/problems/triangle/?envType=study-plan-v2&envId=top-interview-150
#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    vector<vector<int>> memo;
public:
    int dfs(vector<vector<int>>& triangle, int i, int j){
        if(i == triangle.size()){
            return 0;
        }
        if(memo[i][j] != INT_MAX){
            return memo[i][j];
        }

        memo[i][j] = min(dfs(triangle, i + 1, j), dfs(triangle, i + 1, j + 1)) + triangle[i][j];
        return memo[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        memo.resize(m);
        for(int i = 0; i < m; i++){
            memo[i].resize(i + 1, INT_MAX);  // 第i行有i+1个元素
        }
        return dfs(triangle, 0 , 0);
    }
};



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};