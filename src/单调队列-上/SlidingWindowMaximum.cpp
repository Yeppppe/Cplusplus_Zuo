// 滑动窗口最大值（单调队列经典用法模版）
// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
// 返回 滑动窗口中的最大值 。
// 测试链接 : https://leetcode.cn/problems/sliding-window-maximum/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
public:
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int size = nums.size();
      vector<int> deque(size);
      int h = 0;
      int t = 0;
      for(int i = 0; i < k-1 ;i++){
         while(h<t && nums[deque[t-1]] <= nums[i]){
            t--;
         }
         deque[t++] = i;
      }
      int n = nums.size();
      vector<int> ans;
      for(int l = 0, r = l+k-1; r <= n-1;l++){
         while(h < t && nums[deque[t-1]] <= nums[r]){
            t--;
         }
         deque[t++] = r++;
         ans.push_back(nums[deque[h]]);
         while(h < t && l >= deque[h]){    //* 没有考虑h < t的情况
            h++;
         }
         // if (deque[h] == l) {
			// 	h++;
			// }
      }
      return ans;
   }
};