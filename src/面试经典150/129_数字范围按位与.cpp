// https://leetcode.cn/problems/bitwise-and-of-numbers-range/?envType=study-plan-v2&envId=top-interview-150
//!  对所有数字执行按位与运算的结果是所有对应二进制字符串的公共前缀再用零补上后面的剩余位

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int time = 0;
        while(left < right){
            left = left >> 1;
            right = right >> 1;
            time++;
        }
        return left << time;
    }
};


class Solution2 {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left < right){
            right = right & (right - 1);
        }
        return right;
    }
};