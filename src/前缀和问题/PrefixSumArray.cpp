// https://leetcode.cn/problems/range-sum-query-immutable/description/

#include <iostream>
#include <vector>

using namespace std;
class NumArray {
private:
   vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        sum.resize(nums.size()+1);
        sum[0] = 0;
        for(int i = 1; i <= nums.size(); i++){
            sum[i] = sum[i-1] + nums[i-1];      //* 注意累加和不能简单写成sum[i] += num[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right+1] - sum[left];
    }
};
