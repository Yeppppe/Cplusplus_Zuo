// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/submissions/653057950/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   int maxProfit(vector<int>& prices) {
      int n = prices.size();
      int ans = 0;
      for(int i = 1; i < n; i++){
         ans += max(0,prices[i] - prices[i-1]);
      }
      return ans;
   }
};