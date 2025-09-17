// https://leetcode.cn/problems/two-sum/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(!map.count(target - nums[i])){
                map[nums[i]] = i;
            }
            else{
                return {i, map[target - nums[i]]};
            }
        }
        return vector<int> {};
    }
};