// https://leetcode.cn/problems/subarray-sum-equals-k/description/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int ans = 0;
        int pre = 0;
        for(auto n : nums){
            pre += n;
            if(map.count(pre - k)){
                ans += map[pre - k];
            }
            map[pre]++;
        }
        return ans;
    }
};