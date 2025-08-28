// https://leetcode.cn/problems/spiral-matrix/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;

//! 逐帧学习！！！！
class Solution {
private:
   static constexpr int direction[4][2] = {{0, 1}, {1 , 0},{0 , -1},{-1, 0}};     //! static表示类的静态成员变量   constexpr表示这是一个编译期常量，在编译阶段就能确定
public:
   vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      vector<int> ans(m*n);
      int total = m*n;
      int row = 0, column = 0;
      int direct_index = 0;
      for(int i = 0; i < total; i++){
         ans[i] = matrix[row][column];
         visited[row][column] = true;
         int nextrow = row + direction[direct_index][0];
         int nextcolumn = column + direction[direct_index][1];
         if(nextrow < 0 || nextrow >= m || nextcolumn < 0 || nextcolumn >= n || visited[nextrow][nextcolumn] == true){
            direct_index = (direct_index + 1) % 4;
         }
         row += direction[direct_index][0];
         column += direction[direct_index][1];
      }
      return ans;
   }
};