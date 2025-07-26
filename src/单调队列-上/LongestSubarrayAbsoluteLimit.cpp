// 绝对差不超过限制的最长连续子数组
// 给你一个整数数组 nums ，和一个表示限制的整数 limit
// 请你返回最长连续子数组的长度
// 该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit
// 如果不存在满足条件的子数组，则返回 0
// 测试链接 : https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
   const int MAXN = 100001;
   vector<int> max_deq;
   vector<int> min_deq;
   int max_h;
   int max_t;
   int min_h;
   int min_t;
public:
   Solution():max_deq(MAXN), min_deq(MAXN),max_h(0),max_t(0),min_h(0),min_t(0){}
   int longestSubarray(vector<int>& nums, int limit) {
      int size = nums.size();
      int ans = 0;
      for(int l = 0,r = 0; l < size ;l++){
         while(r < size){
            push(nums,r);
            if(is_ok(nums,limit)){           //* 都正确
               r++;
            }
            else{
               break;
            }
         }
         ans = max(ans , r - l);
         pop(l);
      }

      // 修正：先移动右指针扩展窗口，再调整左指针      //! 也是正确的
   //    for(int left = 0,right = 0; right < size; right++){
   //       push(nums, right);  // 先将当前元素加入队列
         
   //       // 当窗口不满足条件时，移动左指针收缩窗口
   //       while(nums[max_deq[max_h]] - nums[min_deq[min_h]] > limit){
   //           pop(left);
   //           left++;
   //       }
         
   //       // 修正：正确计算窗口长度
   //       ans = max(ans, right - left + 1);
   //   }
      return ans;
   }

   bool is_ok(vector<int>& nums,int limit){
      int max_num = max_h < max_t ? nums[max_deq[max_h]] : 0;
      int min_num = min_h < min_t ? nums[min_deq[min_h]] : 0;
      return max_num - min_num <= limit;
   }

   void push(vector<int>& nums , int r){
      while(max_h < max_t && nums[r] >= nums[max_deq[max_t-1]]){
         max_t--;
      }
      max_deq[max_t++] = r;
      while(min_h < min_t && nums[r] <= nums[min_deq[min_t-1]]){
         min_t--;
      }
      min_deq[min_t++] = r;
   }

   void pop(int l){
      if(max_h < max_t && l == max_deq[max_h]){
         max_h++;
      }
      if(min_h < min_t && l == min_deq[min_h]){
         min_h++;
      }
   }
};

