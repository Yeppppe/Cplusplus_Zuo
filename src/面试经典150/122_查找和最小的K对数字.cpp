// https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>& a, vector<int>& b){
            return a[0] > b[0];
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        priority_queue<vector<int>,vector<vector<int>>, cmp> minheap;

        for(int i = 0; i < min(m, k); i++){
            minheap.push({nums1[i] + nums2[0], i, 0});
        }
        vector<vector<int>> ans;
        while(k-- && !minheap.empty()){
            vector<int> cur = minheap.top();
            minheap.pop();
            ans.push_back({nums1[cur[1]], nums2[cur[2]]});

            if(cur[2] + 1 < n){
                minheap.push({nums1[cur[1]] + nums2[cur[2] + 1], cur[1], cur[2] + 1});      //! 当取出当前最小的组合后 下一个最可能的组合是[cur1] + [cur2 + 1]的组合
            }
        }
        return ans;
    }
}; 