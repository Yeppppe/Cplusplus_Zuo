// 随机快速排序，acm练习风格
// 测试链接 : https://www.luogu.com.cn/problem/P1177
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过

// 随机快速排序，填函数练习风格
// 测试链接 : https://leetcode.cn/problems/sort-an-array/
#include <iostream>
#include <random>
#include <vector>
using namespace std;
class Solution {
public:
   vector<int> sortArray(vector<int>& nums) {
      int n = nums.size();
      quicksort(nums,0,n-1);
      return nums;
   }

   int get_random(int l, int r){
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<int> dist(l,r);
      return dist(gen);
   }

   void swap(vector<int>& nums, int a, int b){
      int tmp = nums[a];
      nums[a] = nums[b];
      nums[b] = tmp;
   }

   void quicksort(vector<int> & nums,int l, int r){
      if(l >= r) return;
      int rand = get_random(l,r);
      int x = nums[rand];
      int start,end;
      partition(nums,l, r, x, start , end);
      quicksort(nums,l,start - 1);
      quicksort(nums,end+1,r);
   }

   void partition(vector<int> & nums,int l, int r,int x, int &start, int &end){
      start = l;
      end = r;
      for(int i = start; i <= end;){
         if(nums[i] < x){
            swap(nums,start,i);
            start++;
            i++;
         }
         else if(nums[i] == x){
            i++;
         }
         else{
            swap(nums,i,end);
            end--;
         }
      }
   }
};




class Solution {
public:
   vector<int> sortArray(vector<int>& nums) {
      int n = nums.size();
      quicksort(nums, 0 , n-1);
      return nums;
   }

   void swap(vector<int>& nums, int a, int b){
      int tmp = nums[a];
      nums[a] = nums[b];
      nums[b] = tmp;
   }

   int get_random(int l, int r){
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<int> dist(l,r);
      return dist(gen);
   }


   void quicksort(vector<int>& nums,int l, int r){
      if(l >= r) return;
      int x = nums[get_random(l,r)];
      int start,end;
      partition(nums, x, l , r, start, end);
      quicksort(nums,l,start-1);
      quicksort(nums,end+1 , r);
   }

   void partition(vector<int> &nums, int x, int l, int r, int &start, int &end){
      start = l;
      end = r;
      int i = start;
      while(i <= end){
         if(nums[i] == x){
            i++;
         }
         else if(nums[i] < x){
            swap(nums, i++,start++);
         }
         else{
            swap(nums, i,end--);
         }
      }
   }
};


int get_random(int l , int r){
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<int> dist(l,r);
   return dist(gen);
}