// https://leetcode.cn/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
   vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> L(n);
      L[0] = nums[0];
      vector<int> R(n);
      R[n - 1] = nums[n - 1];
      for(int i = 1; i < n; i++){
         L[i] = L[i-1] * nums[i]; 
      }
      for(int i = n - 2; i >= 0; i--){
         R[i] = R[i + 1] * nums[i];
      }
      vector<int> answer(nums);
      for(int i = 0; i < n; i++){
         int left = i - 1 >= 0 ? L[i - 1] : 1;
         int right = i + 1 < n ? R[i + 1] : 1;
         answer[i] = left*right;
      }
      return answer;
   }
};