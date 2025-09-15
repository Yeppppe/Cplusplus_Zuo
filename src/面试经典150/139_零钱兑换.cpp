// https://leetcode.cn/problems/coin-change/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    vector<int> memo;
public:
    int dfs(vector<int>& coins, int target){
        if(target == 0){
            return 0;
        }
        if(target < 0){
            return INT_MAX/2;
        }
        if(memo[target] != -1) return memo[target];
        int best = INT_MAX / 2;
        for(auto c : coins){
            best = min(best, dfs(coins, target - c)+1);
        }
        return memo[target] = best;

    }
    int coinChange(vector<int>& coins, int amount) {
        memo.resize(amount + 1, -1);
        int ans = dfs(coins, amount);
        return ans == INT_MAX/2 ? -1 : ans;
    }
};

