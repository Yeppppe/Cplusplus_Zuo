// https://leetcode.cn/problems/gas-station/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int sum = 0;
      int n = gas.size();
      for(int i = 0; i < n; i++){
         sum = 0;
         for(int j = 0; j < n; j++){
            sum += gas[(i + j)%n] - cost[(i + j)%n];      //! 重点在于如果当前位置发现不行，那在这区间的都不行，可以直接跳过从下一个位置开始
            if(sum < 0){
               i = i + j;
               break;
            }
         }
         if(sum >= 0)
            return i;
      }
      return -1;
   }
};
