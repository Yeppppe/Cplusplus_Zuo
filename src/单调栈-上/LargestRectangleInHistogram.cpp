// 柱状图中最大的矩形
// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度
// 每个柱子彼此相邻，且宽度为 1 。求在该柱状图中，能够勾勒出来的矩形的最大面积
// 测试链接：https://leetcode.cn/problems/largest-rectangle-in-histogram

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//! 最基本的解法，找到左右两边比自己小的最近的索引，之后算面积进行比较
class Solution {
public:
   int largestRectangleArea(vector<int>& heights) {
      int n = heights.size();
      vector<vector<int>> ans(n,vector<int>(2,-1));
      vector<int> stack;
      for(int i = 0; i < n; i++){
         while (!stack.empty() && heights[i] <= heights[stack.back()])
         {
            int cur = stack.back();
            stack.pop_back();
            int left = stack.empty()?-1:stack.back();
            ans[cur][0] = left;
            ans[cur][1] = i;
         }
         stack.push_back(i);
      }

      int stack_size = stack.size();
      for(int i = stack_size - 1; i >= 0; i--){
         int cur = stack[i];
         int left = i-1 >=0 ? stack[i-1] : -1;
         ans[cur][0] = left;
         ans[cur][1] = n;
      }

      for(int i = n - 2; i >=0; i--){
         if(ans[i][1] != n && heights[ans[i][1]] == heights[i]){
            ans[i][1] = ans[ans[i][1]][1];
         }
      }
      int area = INT_MIN;
      for(int i =0; i < n;i++){
         area = max(area,(ans[i][1]-ans[i][0]-1)*heights[i]);
      }
      return area;
   }

};




//! 更快的解法   直接0ms击败百分之百
class Solution {
public:
   int largestRectangleArea(vector<int>& heights) {
      int n = heights.size();
      vector<int> stack;
      int area = INT_MIN;
      for(int i = 0; i < n; i++){
         while(!stack.empty() && heights[i] <= heights[stack.back()]){
            int cur = stack.back();
            stack.pop_back();
            int left = !stack.empty() ? stack.back() : -1;
            area = max(area,(i - left - 1)*heights[cur]);
         }
         stack.push_back(i);
      }

      int size = stack.size();
      for(int i = size - 1; i>=0;i--){
         int left = i - 1 >= 0 ? stack[i-1] : -1;
         area = max(area , heights[stack[i]]*(n - left - 1));
      }

      return area;
   }
};