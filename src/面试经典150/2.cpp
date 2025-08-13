// https://leetcode.cn/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
       int removeElement(vector<int>& nums, int val) {
           int left = 0;
           for(int r = 0; r < nums.size(); r++){
               if(nums[r] != val){
                   nums[left] = nums[r];
                   left++;    
               }
           }
           return left;
       }
   };
   
   