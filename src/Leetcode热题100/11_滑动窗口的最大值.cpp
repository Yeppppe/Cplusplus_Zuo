// https://leetcode.cn/problems/sliding-window-maximum/description/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>& a, const pair<int, int>& b){
            if(a.first != b.first){
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>,vector<pair<int, int>>, cmp> pq;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < k; i++){
            pq.push(pair(nums[i],i));
        }
        ans.emplace_back(pq.top().first);
        for(int i = k; i < n; i++){
            pq.push(pair(nums[i],i));
            while(pq.top().second < i - k + 1){
                pq.pop();
            }
            ans.emplace_back(pq.top().first);
        }   
        return ans;
    }
};
