// 返回无序数组中累加和为给定值的子数组个数
// 测试链接 : https://leetcode.cn/problems/subarray-sum-equals-k/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
   unordered_map<int,int> map;
public:
    int subarraySum(vector<int>& nums, int k) {
      int sum = 0;
      map[0] = 1;
      int ans = 0;
      for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
            if(map.find(sum - k) != map.end()){      //* 注意这部分使用的是sum - k 
                ans += map[sum - k];
            }
            if(map.find(sum) != map.end())
                map[sum] += 1;
            else 
                map[sum] = 1;
        }
        return ans;
    }
};

