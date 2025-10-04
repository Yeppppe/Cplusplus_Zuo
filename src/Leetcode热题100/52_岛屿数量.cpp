// https://leetcode.cn/problems/number-of-islands/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int m, int n){
        if(grid[m][n] == '0') return;
        grid[m][n] = '0';
        if(m > 0) dfs(grid, m - 1, n);
        if(n > 0) dfs(grid, m, n - 1);
        if(m < grid.size() - 1) dfs(grid, m+1, n);
        if(n < grid[0].size() - 1) dfs(grid, m, n + 1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i , j);
                    ans++;
                }
            }
        }
        return ans;
    }
};