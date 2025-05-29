// 一个正整数如果能被 a 或 b 整除，那么它是神奇的。
// 给定三个整数 n , a , b ，返回第 n 个神奇的数字。
// 因为答案可能很大，所以返回答案 对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/nth-magical-number/

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int lcm = lcm(a,b);
        for(long l=0,r=(long)n*min(a,b),m=0,l<=r;){
            m = (l + r)/2;
            int cnt = m/a + m/b - m/lcm;
            if(n<cnt){
                r = m-1;
            }
            else if(n>cnt){
                l = m+1;
            }
            else
                break;
        }
        return m%1000000007;
    }

    int gcd(int a,int b){
        return b == 0 ? a : gcd(b, a % b);
    }


    int lcm(int a,int b){
        return a/gcd(a,b)*b;
    }
};

