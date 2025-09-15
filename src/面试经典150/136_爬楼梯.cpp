// https://leetcode.cn/problems/climbing-stairs/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;
//! 带记忆化搜索的dfs
class Solution {
private:
    vector<int> memo;
public:
    int dfs(int n){
        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(memo[n] != -1) return memo[n];
        memo[n] = dfs(n - 1) + dfs(n - 2);
        return memo[n];
    }
    int climbStairs(int n) {
        memo.resize(n + 1, -1);
        return dfs(n);
    }
};