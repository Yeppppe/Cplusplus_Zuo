// https://leetcode.cn/problems/sqrtx/?envType=study-plan-v2&envId=top-interview-150

//! 二分法
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x ,ans = -1;
        while(l <= r){
            int mid = (l + r)/2;
            if((long long)mid * mid <= x){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};

