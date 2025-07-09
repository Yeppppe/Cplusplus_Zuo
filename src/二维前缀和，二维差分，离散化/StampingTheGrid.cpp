// 用邮票贴满网格图
// 给你一个 m * n 的二进制矩阵 grid
// 每个格子要么为 0 （空）要么为 1 （被占据）
// 给你邮票的尺寸为 stampHeight * stampWidth
// 我们想将邮票贴进二进制矩阵中，且满足以下 限制 和 要求 ：
// 覆盖所有空格子，不覆盖任何被占据的格子
// 可以放入任意数目的邮票，邮票可以相互有重叠部分
// 邮票不允许旋转，邮票必须完全在矩阵内
// 如果在满足上述要求的前提下，可以放入邮票，请返回 true ，否则返回 false
// 测试链接 : https://leetcode.cn/problems/stamping-the-grid/

// 解题思路
// 这个问题巧妙地结合了二维前缀和和二维差分技术：
// 使用前缀和检查邮票放置可行性：
// 对原矩阵构建前缀和数组，用于快速判断某个矩形区域是否全为0
// 只有当区域内全为0时，才能放置邮票
// 使用差分矩阵记录邮票覆盖情况：
// 不直接修改原矩阵，而是在差分矩阵中记录邮票的放置
// 每放置一张邮票，在差分矩阵中进行标记
// 最后通过还原差分矩阵，得到每个格子被邮票覆盖的次数
// 验证覆盖结果：
// 检查所有空格子是否都被至少一张邮票覆盖


#include <iostream>
#include <vector>
using namespace std;

//!  代码超时！
class Solution {
public:
      void build(vector<vector<int>>& sum){
         int m = sum.size();
         int n = sum[0].size();
         for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
               sum[i][j] +=sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
         }
      }

      int sumRegion(vector<vector<int>>sum ,int a, int b, int c, int d){
         return sum[c][d] - sum[c][b-1] - sum[a-1][d] + sum[a-1][b-1];
      }
      
      void add_label(vector<vector<int>>& label ,int a, int b, int c, int d){
         int m = label.size();
         int n = label[0].size();
         label[a][b] += 1;
         label[a][d+1] -= 1;
         label[c+1][b] -= 1;
         label[c+1][d+1] += 1;
      }
      bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
         int m = grid.size();
         int n = grid[0].size();
         vector<vector<int>>sum(m+1,vector<int>(n+1,0));
         for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
               sum[i+1][j+1] = grid[i][j];
            }
         }
         //* 构建sum前缀和
         build(sum);

         vector<vector<int>>label(m+2,vector<int>(n+2,0));
         for(int i=0,c=i+stampHeight-1;c<m;i++,c++){
            for(int j=0,d = j+stampWidth-1; d<n; j++,d++){
               if (sumRegion(sum,i+1,j+1,c+1,d+1) == 0){
                  add_label(label,i+1,j+1,c+1,d+1);
               }
            }
         }

         build(label);

         for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
               if (grid[i][j] == 0 && label[i+1][j+1] == 0)
                  return false;
            }
         }

         return true;
         
      }
};





//! leetcode代码
class Solution {
public:
   bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
      int m = grid.size(), n = grid[0].size();
      vector<vector<int>> sum(m + 2, vector<int>(n + 2, 0));
      vector<vector<int>> diff(m + 2, vector<int>(n + 2, 0));
      for (int i = 1; i <= m; i++) {
         for (int j = 1; j <= n; j++) {
               sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i - 1][j - 1];
         }
      }

      for (int i = 1; i + stampHeight - 1 <= m; i++) {
         for (int j = 1; j + stampWidth - 1 <= n; j++) {
               int x = i + stampHeight - 1;
               int y = j + stampWidth - 1;
               if (sum[x][y] - sum[x][j - 1] - sum[i - 1][y] + sum[i - 1][j - 1] == 0) {
                  diff[i][j]++;
                  diff[i][y + 1]--;
                  diff[x + 1][j]--;
                  diff[x + 1][y + 1]++;
               }
         }
      }

      for (int i = 1; i <= m; i++) {
         for (int j = 1; j <= n; j++) {
               diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
               if (diff[i][j] == 0 && grid[i - 1][j - 1] == 0) {
                  return false;
               }
         }
      }
      return true;
   }
};