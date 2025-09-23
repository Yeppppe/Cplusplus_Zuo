// https://leetcode.cn/problems/merge-intervals/?envType=study-plan-v2&envId=top-100-liked
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    struct cmp{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        int left = 0, right = 0;
        int n = intervals.size();
        vector<vector<int>> ans;
        left = intervals[0][0];
        right = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] > right){
                ans.push_back({left,right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else{
                right = max(right, intervals[i][1]);
            }
        }
        ans.push_back({left,right});
        return ans;
    }
};
