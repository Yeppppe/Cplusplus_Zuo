// https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        set<int> set;
        for(auto n : nums){
            set.insert(n);
        }
        int ans = 0;
        for(auto s : set){
            if(!set.count(s + 1)){
                int count = 1;
                int cur = s;
                while(set.count(cur - 1)){
                    count++;
                    cur -= 1;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};

