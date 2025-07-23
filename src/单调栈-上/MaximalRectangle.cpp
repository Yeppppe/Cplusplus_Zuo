// 最大矩形
// 给定一个仅包含 0 和 1 、大小为 rows * cols 的二维二进制矩阵
// 找出只包含 1 的最大矩形，并返回其面积
// 测试链接：https://leetcode.cn/problems/maximal-rectangle/



#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
   int maximalRectangle(vector<vector<char>>& matrix) {
      int ans = 0;
      int row_num = matrix.size();
      int col_num = matrix[0].size();
      vector<int> arr(col_num , 0);
      for(int i = 0; i < row_num; i++){
         for(int j = 0; j < col_num; j++){
            arr[j] = matrix[i][j] != '0' ? arr[j] + 1 : 0; 
         }
         ans = max(ans , largestRectangleArea(arr));
      }
      return ans;
   }


//* 直接使用上一组的代码
   // int largestRectangleArea(vector<int>& heights) {
   //    int n = heights.size();
   //    vector<int> stack;
   //    int area = INT_MIN;
   //    for(int i = 0; i < n; i++){
   //       while(!stack.empty() && heights[i] <= heights[stack.back()]){
   //          int cur = stack.back();
   //          stack.pop_back();
   //          int left = !stack.empty() ? stack.back() : -1;
   //          area = max(area,(i - left - 1)*heights[cur]);
   //       }
   //       stack.push_back(i);
   //    }

   //    int size = stack.size();
   //    for(int i = size - 1; i>=0;i--){
   //       int left = i - 1 >= 0 ? stack[i-1] : -1;
   //       area = max(area , heights[stack[i]]*(n - left - 1));
   //    }

   //    return area;
   // }
   int largestRectangleArea(vector<int>& heights){
      vector<int> stack;
      int n = heights.size();
      int ans = 0;
      for(int i = 0; i < n; i++){
         while(!stack.empty() && heights[i] <= heights[stack.back()]){
            int cur = stack.back();
            stack.pop_back();
            int left = stack.empty() ? -1 : stack.back();
            ans = max(ans , (i - left - 1)*heights[cur]);
         }
         stack.push_back(i);
      }

      int size = stack.size();
      for(int i = size-1; i >=0; i--){
         int left = i - 1 >=0 ? stack[i - 1] : -1;
         ans = max(ans , (n - left - 1)*heights[stack[i]]);
      }
      return ans;
   }
};