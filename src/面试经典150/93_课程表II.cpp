// https://leetcode.cn/problems/course-schedule-ii/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> edges(numCourses);
        for(auto p : prerequisites){
            indegree[p[0]]++;
            edges[p[1]].push_back(p[0]);
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto e : edges[cur]){
                if(--indegree[e] == 0){
                    q.push(e);
                }
            }
            ans.push_back(cur);
        }
        return ans.size() == numCourses ? ans : vector<int>{};
    }
};