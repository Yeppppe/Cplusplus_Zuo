// https://leetcode.cn/problems/house-robber/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;
class Solution {
private:
    vector<int> memo;
public:
    int dfs(vector<int>& nums, int cur){
        if(cur >= nums.size()) return 0;
        if(memo[cur] != -1) return memo[cur];
        int a = nums[cur] + dfs(nums, cur + 2);
        int b = dfs(nums, cur + 1);
        memo[cur] = max(a, b);
        return memo[cur];
    }
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return dfs(nums, 0);
    }
}; 