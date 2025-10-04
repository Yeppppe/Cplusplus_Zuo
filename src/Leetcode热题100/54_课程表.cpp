// https://leetcode.cn/problems/course-schedule/?envType=study-plan-v2&envId=top-100-liked
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> edges(numCourses);

        for(auto vec : prerequisites){
            indegree[vec[0]]++;
            edges[vec[1]].push_back(vec[0]);
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
            ans.push_back(cur);
            for(auto n : edges[cur]){
                if(--indegree[n] == 0){
                    q.push(n);
                }
            }
        }
        
        return ans.size() == numCourses ? true : false;
    }
};