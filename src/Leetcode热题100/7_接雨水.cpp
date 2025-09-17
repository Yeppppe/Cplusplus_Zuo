// https://leetcode.cn/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0];
        int rmax = height[n - 1];
        int l = 1;
        int r = n - 2;
        int ans = 0;
        while(l <= r){
            if(lmax < rmax){
                ans += lmax > height[l] ? lmax - height[l] : 0;
                if(lmax < height[l]){
                    lmax = height[l];
                }
                l++;
            }
            else{
                ans += rmax > height[r] ? rmax - height[r] : 0;
                if(rmax < height[r]){
                    rmax = height[r];
                }
                r--;
            }
        }
        return ans;
    }
};