// 数组中两个数的最大异或值
// 测试链接 : https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    static const int MAXN = 3000001;
    int tree[MAXN][2];
    int count;
    int high;

    void build(vector<int>& nums){
        count = 1;
        int max_num = INT_MIN;
        for(auto num : nums){
            max_num = max(max_num,num);
        }
        if(max_num == 0) {
            high = 0;
        } else {
            high = 31 - __builtin_clz(max_num);
        }

        for(auto num : nums){
            insert(num);
        }
    }

    void insert(int num){
        int cur = 1;
        int bit;
        for(int i = high;i>=0;i--){
            bit = (num>>i)&1;
            if(tree[cur][bit] == 0){
                tree[cur][bit] = ++count;
            }
            cur = tree[cur][bit];
        }
    }

    int Xor(int num){
        int ans = 0;
        int status;
        int want;
        int cur = 1;
        for(int i = high; i >= 0; i--){
            status = (num>>i)&1;
            want = status^1;
            if(tree[cur][want]==0){
                want ^= 1;
            }
            // ans |= (status ^ want) << i;
            ans |= (status^want) << i;
            cur = tree[cur][want];
            // ans = max(ans,num^(want<<i));
        }

        return ans;
    }



public:
    int findMaximumXOR(vector<int>& nums) {
        build(nums);
        int ans = 0;
        for(auto num : nums){
            ans = max(ans,Xor(num));
        }
        return ans;
    }
};