// https://leetcode.cn/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;

//! 提前预留版本
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> next;
        next.push_back(0);
        int carry = 1;
        next.insert(next.end(), digits.begin(), digits.end());
        for(int i = n; i >=0; i--){
            next[i] = (next[i] + carry) % 10;
            carry = next[i] == 0 ? 1 : 0;
            if(carry == 0) break;
        }

        vector<int> ans;
        if(next[0] == 0){
            ans.insert(ans.end(), next.begin() + 1, next.end());
        }
        else{
            ans.insert(ans.end(), next.begin(), next.end());
        }
        return ans;
    }
};