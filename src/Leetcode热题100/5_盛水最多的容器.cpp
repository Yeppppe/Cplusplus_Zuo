// https://leetcode.cn/problems/container-with-most-water/?envType=study-plan-v2&envId=top-100-liked
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int l = 0;
        int r = n - 1;
        while(l < r){
            int cur_height = min(height[l], height[r]);
            ans = max(ans, cur_height * (r - l));
            if(cur_height == height[l]) l++;
            else r--;
        }
        return ans;
    }
};