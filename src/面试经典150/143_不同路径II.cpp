// https://leetcode.cn/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> memo;
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 0){
            return 0;
        }

        if(i == grid.size() - 1 && j == grid[0].size() - 1){
            return 1;
        }

        if(memo[i][j] != -1) return memo[i][j];

        grid[i][j] = 2;
        memo[i][j] = dfs(grid, i + 1, j) + dfs(grid, i, j + 1);
        grid[i][j] = 0;
        return memo[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memo.resize(m, vector<int>(n , -1));
        return dfs(obstacleGrid, 0 , 0);
    }
};