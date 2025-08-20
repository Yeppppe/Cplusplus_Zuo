// https://leetcode.cn/problems/h-index/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
   int hIndex(vector<int>& citations) {
      int n = citations.size();
      int ans = n;
      int count;
      while(ans){
         count = 0;
         for(int i = 0; i < n; i++){
               if(citations[i] >= ans){
                  count++;
               }
         }
         if(count >= ans){
               return ans;
         }
         ans--;
      }
      return ans;
   }
};