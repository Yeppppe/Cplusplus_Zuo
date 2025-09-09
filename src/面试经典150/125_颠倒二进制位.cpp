// https://leetcode.cn/problems/reverse-bits/?envType=study-plan-v2&envId=top-interview-150

#include <cstdint>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res;
        for(int i = 0; i < 32; i++){
            res |= (n & 1) << (31 - i);
            n = n >> 1;
        }
        return res;
    }
};