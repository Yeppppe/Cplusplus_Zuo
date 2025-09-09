// https://leetcode.cn/problems/ipo/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;
#include <queue>
#include <algorithm>
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for(int i = 0; i < n; i++){
            projects.emplace_back(pair(capital[i], profits[i]));
        }
        sort(projects.begin(), projects.end(), [](pair<int, int>&a , pair<int, int>&b){
                return a.first < b.first;
            }
        );
        int id = 0;
        priority_queue<int, vector<int>, less<int>> maxheap;
        while(k--){
            while(id < n && w >= projects[id].first){               //! 这里需要注意限制id的大小
                maxheap.push(projects[id].second);
                id++;
            }
            if(maxheap.empty()) break;
            w += maxheap.top();
            maxheap.pop();
        }
        return w;
    }
};