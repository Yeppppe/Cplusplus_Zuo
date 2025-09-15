// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> pre(n , 0);
        int curp = 0;
        int min_pri = prices[0];
        for(int i = 1; i < n; i++){
            if(prices[i] < min_pri){
                min_pri = prices[i];
            }
            else{
                curp = max(curp, prices[i] - min_pri);
            }
            pre[i] = curp;
        }

        int back_max = prices[n - 1];
        int ans = 0;
        curp = 0;
        for(int i = n - 2; i >= 0; i--){
            if(prices[i] > back_max){
                back_max = prices[i];
            }
            else{
                curp = max(curp, back_max - prices[i]);
            }
            ans = max(ans, curp + pre[i]);
        }
        return ans;
    }
};


//! 状态转移的方法，有点看不懂：
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0];
        int sell1 = 0;
        int buy2 = -prices[0];
        int sell2 = 0;

        for(int i = 1; i < n; i++){
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1-prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};