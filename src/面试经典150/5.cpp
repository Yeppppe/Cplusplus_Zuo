// https://leetcode.cn/problems/majority-element/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
   int majorityElement(vector<int>& nums) {
      unordered_map<int,int> map;
      for(auto n : nums){
         if(map.find(n) != map.end()){
               map[n]++;
         }
         else{
               map[n] = 1;
         }
         if(map[n] > nums.size()/2) return n;
      }
      return 0;
   }
};