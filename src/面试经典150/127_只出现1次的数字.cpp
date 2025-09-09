// https://leetcode.cn/problems/single-number/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto n : nums){
            ans ^= n;
        }
        return ans;
    }
};