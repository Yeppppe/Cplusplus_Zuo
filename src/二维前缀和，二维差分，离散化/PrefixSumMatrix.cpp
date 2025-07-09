// 利用二维前缀和信息迅速得到二维区域和
// 测试链接 : https://leetcode.cn/problems/range-sum-query-2d-immutable/

// 构造函数：
// 创建(n+1)×(m+1)大小的前缀和数组
// 先将原矩阵的值复制到前缀和数组的对应位置
// 然后计算每个位置的前缀和，利用上述递推公式
// sumRegion方法：
// 输入坐标(a,b)到(c,d)表示需要计算的矩形区域
// 将c和d分别加1转换为前缀和数组的索引
// 使用前缀和公式计算区域和

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sum;    //* 私有成员如果是引用的话必须一开始就进行初始化
public:
   NumMatrix(vector<vector<int>>& matrix) {     //* 构造函数
      int m = matrix.size();
      int n = m > 0 ? matrix[0].size() : 0;
      sum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
      
      for(int i = 0; i < m; i++){
         for(int j = 0; j < n; j++){
            sum[i+1][j+1] = matrix[i][j];
         }
      }
      for (int i = 1; i <= m; i++){
         for(int j = 1; j <= n; j++){
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + sum[i][j];
         }
      }
   }
   
   int sumRegion(int row1, int col1, int row2, int col2) {
      row2++;
      col2++;
      return sum[row2][col2] - sum[row1][col2] - sum[row2][col1] + sum[row1][col1];
   }
};
