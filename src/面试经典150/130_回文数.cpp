// https://leetcode.cn/problems/palindrome-number/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<int> nums;
        while(x > 0){
            nums.push_back(x % 10);
            x = x/10;
        }
        int n = nums.size();
        int l = 0;
        int r = n -1;
        while(l < r){
            if(nums[l++] != nums[r--]) return false;
        }
        return true;
    }
};


//! 完全反转一个数字的方法
class Solution2 {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long rev = 0;
        int origin = x;
        while(x > 0){
            int pre = x %10;
            rev = rev * 10 + pre;
            x = x/10;
        }
        return rev == origin;
    }
};
