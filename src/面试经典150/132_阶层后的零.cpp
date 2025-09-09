// https://leetcode.cn/problems/factorial-trailing-zeroes/solutions/1360892/jie-cheng-hou-de-ling-by-leetcode-soluti-1egk/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for(int i = 5; i <= n; i += 5){
            for(int x = i; x % 5 ==0; x= x/5){
                ans++;
            }
        }
        return ans;
    }
};


//! 还是不太明白
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
