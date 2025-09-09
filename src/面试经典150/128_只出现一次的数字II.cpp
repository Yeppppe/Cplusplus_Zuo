// https://leetcode.cn/problems/single-number-ii/?envType=study-plan-v2&envId=top-interview-150


#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(32, 0);
        for(auto n : nums){
            for(int i = 0; i < 32; i++){
                if((n & 1) == 1){                   //(n >> 1) & 1 == 1也可以
                    count[i] += 1;
                }
                n = n >> 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(count[i]%3 != 0){
                ans |= 1 << i;
            }
        }
        return ans;
    }
};