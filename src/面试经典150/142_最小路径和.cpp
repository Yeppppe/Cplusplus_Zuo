// https://leetcode.cn/problems/minimum-path-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;
#include <algorithm>
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sum(m,vector<int>(n, 0));
        sum[0][0] = grid[0][0];
        for(int i = 1; i < n; i++){
            sum[0][i] = grid[0][i] + sum[0][i - 1];
        }
        for(int j = 1; j < m; j++){
            sum[j][0] = grid[j][0] + sum[j - 1][0];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
            }
        }

        return sum[m - 1][n - 1];
    }
};