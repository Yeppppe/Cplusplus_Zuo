// https://leetcode.cn/problems/number-of-islands/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y){
        int m = grid.size();
        int n = grid[0].size();

        grid[x][y] = '0';
        if(x - 1 >= 0 && grid[x - 1][y] == '1') dfs(grid, x - 1, y);
        if(x + 1 < m && grid[x + 1][y] == '1') dfs(grid, x + 1, y);
        if(y - 1 >= 0 && grid[x][y - 1] == '1') dfs(grid, x, y - 1);
        if(y + 1 < n && grid[x][y + 1] == '1') dfs(grid, x, y + 1);
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

