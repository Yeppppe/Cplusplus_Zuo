// 打砖块
// 有一个 m * n 的二元网格 grid ，其中 1 表示砖块，0 表示空白
// 砖块 稳定（不会掉落）的前提是：
// 一块砖直接连接到网格的顶部，或者
// 至少有一块相邻（4 个方向之一）砖块 稳定 不会掉落时
// 给你一个数组 hits ，这是需要依次消除砖块的位置
// 每当消除 hits[i] = (rowi, coli) 位置上的砖块时，对应位置的砖块（若存在）会消失
// 然后其他的砖块可能因为这一消除操作而 掉落
// 一旦砖块掉落，它会 立即 从网格 grid 中消失（即，它不会落在其他稳定的砖块上）
// 返回一个数组 result ，其中 result[i] 表示第 i 次消除操作对应掉落的砖块数目。
// 注意，消除可能指向是没有砖块的空白位置，如果发生这种情况，则没有砖块掉落。
// 测试链接 : https://leetcode.cn/problems/bricks-falling-when-hit/

// 1. 炮弹位置 - 1
// 2. 天花板填充 天花板的1 -> 2
// 3. 时光倒流，处理炮弹 + 1，然后感染周围的1 看能多出几个2，多出来的就是能打下来的，
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
public:
   vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
      int row = grid.size();
      if (row == 0) return {};  // 增加空网格判断
      int col = grid[0].size();
      vector<int> ans(hits.size() , 0);
      if (row == 1) {
         return ans;
      }
      // 先处理所有击打
      for(auto& h : hits){
         if (h[0] >= 0 && h[0] < row && h[1] >=0 && h[1] < col) {  // 增加有效性检查
               grid[h[0]][h[1]]--;
         }
      }
      // 标记初始状态下与顶部相连的砖块
      for(int j = 0; j < col; j++){
         dfs(grid ,0, j);
      }
      // 逆向恢复击打
      for(int i = hits.size()-1; i >= 0; i--){
         int x = hits[i][0];  // 修改变量名，避免与m、n冲突
         int y = hits[i][1];  // 修改变量名，避免与m、n冲突
         
         // 检查坐标有效性
         if (x < 0 || x >= row || y < 0 || y >= col) {
               continue;
         }
         
         grid[x][y]++;
         if(worth(grid, x, y)){
            ans[i] =  dfs(grid , x, y) - 1;
         }
      }
      return ans;
   }

   int dfs(vector<vector<int>>& grid ,int i ,int j){
      // 严格的边界检查
      if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1){
         return 0;
      }
      grid[i][j] = 2;  // 标记为已连接顶部
      // 递归检查四个方向
      return 1 + dfs(grid, i + 1, j) + dfs(grid, i, j + 1) + dfs(grid, i - 1, j) + dfs(grid, i, j - 1);
   }

   bool worth(vector<vector<int>>& grid , int i, int j) {
      int rows = grid.size();
      int cols = grid[0].size();
      // 检查当前位置是否是砖块，以及是否与顶部或已连接顶部的砖块相邻
      return grid[i][j] == 1 && 
               (i == 0 || 
               (i > 0 && grid[i - 1][j] == 2) || 
               (i < rows - 1 && grid[i + 1][j] == 2) || 
               (j > 0 && grid[i][j - 1] == 2) || 
               (j < cols - 1 && grid[i][j + 1] == 2));
   }

};
