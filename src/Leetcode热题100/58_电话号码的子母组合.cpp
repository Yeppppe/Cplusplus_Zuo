// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void dfs(vector<string>& res, unordered_map<char, string>& map, int cur, string& digits, string tmp){
        if(cur == digits.size()){
            res.push_back(tmp);
            return;
        }

        for(auto c : map[digits[cur]]){
            tmp.push_back(c);
            dfs(res, map, cur + 1, digits, tmp);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return vector<string>{};
        unordered_map<char, string> map = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

        vector<string> res;
        string tmp;
        dfs(res,map,0,digits,tmp);
        return res;
    }
};