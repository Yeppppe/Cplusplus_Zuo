// https://leetcode.cn/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;
//! 错误的写法
class Solution {
public:
   void dfs_row(vector<vector<int>>& matrix, int i, int j,int m, int n){
      if(i < 0 || i >= m || j < 0 || j >=n){
         return;
      }
      matrix[i][j] = 0;
      dfs_row(matrix, i + 1, j, m, n);       //! 这里递归会无限循环
      dfs_row(matrix, i - 1, j, m, n);
   }

   void dfs_col(vector<vector<int>>& matrix, int i, int j,int m, int n){
      if(i < 0 || i >= m || j < 0 || j >=n){
         return;
      }
      matrix[i][j] = 0;
      dfs_col(matrix, i, j - 1, m, n);
      dfs_col(matrix, i, j + 1, m, n);
   }

   void setZeroes(vector<vector<int>>& matrix) {
      vector<vector<int>> need;
      int m = matrix.size();
      int n = matrix[0].size();
      for(int i = 0; i < m; i++){
         for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
               need.push_back({i,j});
            }
         }
      }
      for(auto ne : need){
         dfs_row(matrix,ne[0],ne[1],m,n);
         dfs_col(matrix,ne[0],ne[1],m,n);
      }
      return;
   }
};



//! 豆包解法
class Solution {
public:
   void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      vector<bool> row(m, false);  // 标记需要置零的行
      vector<bool> col(n, false);  // 标记需要置零的列
      
      // 首先遍历矩阵，标记需要置零的行和列
      for (int i = 0; i < m; ++i) {
         for (int j = 0; j < n; ++j) {
               if (matrix[i][j] == 0) {
                  row[i] = true;
                  col[j] = true;
               }
         }
      }
      
      // 根据标记，将相应的行和列置零
      for (int i = 0; i < m; ++i) {
         for (int j = 0; j < n; ++j) {
               if (row[i] || col[j]) {
                  matrix[i][j] = 0;
               }
         }
      }
   }
};
   