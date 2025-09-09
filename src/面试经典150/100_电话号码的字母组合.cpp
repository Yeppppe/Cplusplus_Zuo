// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-interview-150

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if(digits.empty()){
            return combinations;
        }
        unordered_map<char, string> map{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination;
        backtrace(combinations,map,digits, 0, combination);
        return combinations;
    }

    void backtrace(vector<string>&combination, unordered_map<char, string>& map,const string digits, int index, string& res){
        if(index == digits.size()){
            combination.push_back(res);
            return;
        }
        char digit = digits[index];
        for(auto c : map[digit]){
            res.push_back(c);
            backtrace(combination,map,digits, index + 1, res);
            res.pop_back();
        }
    }
};