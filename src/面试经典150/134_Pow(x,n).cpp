// https://leetcode.cn/problems/powx-n/?envType=study-plan-v2&envId=top-interview-150


//! 递归调用
class Solution {
public:
    double dfs(double x, long long n){
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n < 0) return(1/dfs(x, -n));

        double y = dfs(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x;
    }
    double myPow(double x, int n) {
        long long N = n;
        return dfs(x, N);
    }
};