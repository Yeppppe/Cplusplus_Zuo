// https://leetcode.cn/problems/search-a-2d-matrix/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> sortnum;
        for(auto & m : matrix){
            sortnum.insert(sortnum.end(), m.begin(), m.end());
        }
        int n = sortnum.size();
        int l = 0, r = n - 1;
        int ans = 0;
        if(target == sortnum[0]) return true;
        while(l <= r){
            int mid = (l + r)/2;
            if(sortnum[mid] == target) return true;
            if(sortnum[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return false;
    }
};

