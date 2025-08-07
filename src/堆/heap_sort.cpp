
// 堆排序 ：  https://leetcode.cn/problems/sort-an-array/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//! 直接使用优先级队列
class Solution {
public:
   vector<int> sortArray(vector<int>& nums) {
      priority_queue<int,vector<int>,greater<int>> que;
      for(auto n : nums){
         que.push(n);
      }
      vector<int> ans;
      while(!que.empty()){
         ans.push_back(que.top());
         que.pop();
      }
      return ans;
   }
};


//! 维护小根堆的写法
class Solution {
public:
   vector<int> sortArray(vector<int>& nums) {
      vector<int> ans;
      for(auto n : nums){
         heapinsert(ans,n);
      }
      vector<int> ret;
      int n = ans.size();
      while(n--){
         ret.push_back(ans[0]);
         swap(ans,0,n);
         ans.pop_back();
         heapify(ans,0);
      }
      return ret;
   }

   void heapinsert(vector<int>& nums,int x){
      int n = nums.size();
      nums.push_back(x);
      int i = n;
      while(i > 0 && nums[i] < nums[(i - 1)/2]){
         swap(nums,i,(i-1)/2);
         i = (i - 1) / 2;
      }
   }

   void heapify(vector<int>& nums,int i){
      int n = nums.size();
      while(i * 2 + 1 < n){
         // int better = i*2 + 2 < n ? (nums[i*2 + 1] < nums[i*2+2] ? i *2 + 1 : i*2 +2) : i * 2 + 1;
         int better = (i*2 + 2 < n && nums[i*2+2] < nums[i*2+1]) ? i*2+2 : i*2+1;
         if(nums[i] > nums[better]){
            swap(nums, i , better);
            i = better;
         } 
         else{
            break;
         }
      }
   }

   void swap(vector<int> &nums,int a,int b){
      int tmp = nums[a];
      nums[a] = nums[b];
      nums[b] = tmp;
   }
};