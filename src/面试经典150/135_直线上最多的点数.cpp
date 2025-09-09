// https://leetcode.cn/problems/max-points-on-a-line/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return points.size();
        int res = 0;
        int t;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                t = 2;
                for(int k = 0; k < j; k++){
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    if((y3 - y2) * (x2 - x1) == (y2 - y1) * (x3 - x2))
                        t++;
                }
                res = max(res, t);
            }
        }
        return res;
    }
};