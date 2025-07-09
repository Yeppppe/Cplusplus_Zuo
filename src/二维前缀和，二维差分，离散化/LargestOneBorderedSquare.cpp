// 边框为1的最大正方形
// 给你一个由若干 0 和 1 组成的二维网格 grid
// 请你找出边界全部由 1 组成的最大 正方形 子网格
// 并返回该子网格中的元素数量。如果不存在，则返回 0。
// 测试链接 : https://leetcode.cn/problems/largest-1-bordered-square/


// 解题思路
// 二维前缀和预处理：
// 将原始二维数组转换为前缀和数组，每个位置g[i][j]存储从(0,0)到(i,j)矩形区域内所有元素的和
// 通过build函数实现，使用递推公式：g[i][j] += g[i][j-1] + g[i-1][j] - g[i-1][j-1]
// 正方形边框判断：
// 对于一个正方形，其边框上的1的数量应该是：(边长-1) × 4
// 判断方法：计算整个正方形区域的和，减去内部区域的和，如果等于(边长-1) × 4，则边框全为1
// 枚举查找：
// 从边长为1开始，枚举所有可能的正方形
// 对每个可能的左上角点(a,b)，尝试扩展边长，找到最大的合法正方形
// 使用前缀和快速计算区域和，避免重复遍历

//! 始终有三道A不出来 通过率81/84
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
       vector<vector<int>> sum;
       int m;
       int n;
    public:
       int largest1BorderedSquare(vector<vector<int>>& grid) {
          m = grid.size();
          n = m > 0 ? grid[0].size() : 0;
          int ans = 0;
          sum = vector<vector<int>>(m+1 , vector<int>(n+1,0));
    
          for(int i = 0; i < m; i++){
             for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                   ans = 1;
                   break;
                }
             }
          }
    
          if(ans == 0) return 0;
    
          //* 初始化前缀和数组
          for(int i = 0; i < m; i++){
             for(int j = 0; j < n; j++){
                sum[i+1][j+1] = grid[i][j];
             }
          }
    
          //* 创建前缀和数组
          for(int i = 1; i < m+1; i++){
             for(int j = 1; j < n+1; j++){
                sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + sum[i][j];
             }
          }
    
          for(int i = 1; i <= m; i++){
             for(int j = 1; j <= n; j++){
                for(int c = i+ans,d = j+ans,k = ans+1;c<=m && d<=n;c++,d++,k++){
                   if((get_square(sum,i,j,c,d)-get_square(sum,i+1,j+1,c-1,d-1)) == (k-1)*4)
                      ans = k;
                }
             }
          }
          return ans*ans;
       }
    
       int get_square(vector<vector<int>>& g,int a,int b, int c, int d){
          if((a>=c) || (b>=d)){
             return 0;
          }
          return g[c][d] - g[c][b-1] - g[a-1][d] + g[a-1][b-1];
       }
    
    };