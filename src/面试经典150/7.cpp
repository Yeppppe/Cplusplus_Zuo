
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   int maxProfit(vector<int>& prices) {
      int n = prices.size();
      if(n <= 1) return 0;
      int cur_min = prices[0];
      int ans = INT_MIN;
      for(int i = 1; i < n; i++){
         cur_min = min(cur_min,prices[i]);
         ans = max(prices[i] - cur_min , ans);
      }   
      return ans;
   }
};