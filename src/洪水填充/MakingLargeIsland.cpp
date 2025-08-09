// 最大人工岛
// 给你一个大小为 n * n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
// 返回执行此操作后，grid 中最大的岛屿面积是多少？
// 岛屿 由一组上、下、左、右四个方向相连的 1 形成
// 测试链接 : https://leetcode.cn/problems/making-a-large-island/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   int largestIsland(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      int id = 2;
      for(int i = 0; i < m; i++){
         for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
               dfs(grid, i, j, m, n, id++);
            }
         }
      }
      vector<int> size(id,0);                //* 这个size大小如果简单设置为m*n会导致堆溢出
      int ans = 0;
      for(int i = 0; i < m; i++){
         for(int j = 0; j < n; j++){
            if(grid[i][j] > 1){
               size[grid[i][j]]++;
               ans = max(ans , size[grid[i][j]]);
            }
         }
      }

      vector<bool> visit(m*n,false);
      // int up = 0;
      // int down = 1;
      // int left = 2;
      // int right = 3;
      int all = 0;
      for(int i = 0; i < m; i++){
         for(int j = 0; j < n; j++){
            if(grid[i][j] == 0){
               int up = j > 0 ? grid[i][j-1] : 0;
               int down = j + 1 < n ? grid[i][j+1] : 0;
               int left = i > 0 ? grid[i-1][j] : 0;
               int right = i+1 < m ? grid[i+1][j] : 0;
               all = 1 + size[up];
               visit[up] = true;
               if(!visit[down]){
                  all += size[down];
                  visit[down] = true;
               }
               if(!visit[left]){
                  all += size[left];
                  visit[left] = true;
               }
               if(!visit[right]){
                  all += size[right];
                  visit[right] = true;
               }
               ans = max(ans, all);
               visit[up] = false;
               visit[down] = false;
               visit[left] = false;
               visit[right] = false;
            }
         }
      }
      return ans;
   }

   void dfs(vector<vector<int>>& grid , int i, int j, int m, int n, int id){
      if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1){
         return;
      }
      grid[i][j] = id;
      dfs(grid,i - 1, j , m , n, id);
      dfs(grid,i + 1, j , m , n, id);
      dfs(grid,i, j - 1 , m , n, id);
      dfs(grid,i, j + 1 , m , n, id);
   }
};

