// https://leetcode.cn/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1);
        vector<int> bac(n, 1);
        pre[0] = nums[0];
        bac[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] * nums[i];
        }
        for(int i = n - 2; i >= 0; i--){
            bac[i] = bac[i + 1] * nums[i];
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int p = (i - 1 >= 0) ? pre[i - 1] : 1;
            int b = (i + 1 < n) ? bac[i + 1] : 1;
            ans.push_back(p * b);
        }
        return ans;
    }
};