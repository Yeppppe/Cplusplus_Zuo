// https://leetcode.cn/problems/number-of-1-bits/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    int hammingWeight(int n) {
        int sum = 0;
        for(int i = 0; i < 32; i++){
            if(n > 0 && n & 1 == 1){
                sum++;
            }
            n = n >> 1;
        }
        return sum;
    }
};