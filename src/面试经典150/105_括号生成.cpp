// https://leetcode.cn/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <string>
using namespace std;

//! 暴力遍历法，遍历出所有的可能性，找到其中合理的
class Solution {
public:
    vector<string> ans;
    bool isvalid(string& str){
        int count = 0;
        for(auto c : str){
            if(c == '('){
                count++;
            }
            else if(c == ')'){
                count--;
            }
            if(count < 0) return false;
        }
        return count == 0;
    }

    void generateall(int cur, int n, string& res){
        if(cur == n){
            ans.push_back(res);
            return;
        }

        res.push_back('(');
        generateall(cur + 1, n , res);
        res.pop_back();

        res.push_back(')');
        generateall(cur + 1, n , res);
        res.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string res;
        generateall(0,2*n,res);
        vector<string> final;
        for(auto str : ans){
            if(isvalid(str))
                final.push_back(str);
        }
        return final;
    }
};




//! 稍微好一点的解法
class Solution2 {
public:
    bool check(string& str){
        int count = 0;
        for(auto c : str){
            if(c == '(') 
                count++;
            else 
                count--;
            if(count < 0) return false;
        }
        return count == 0;
    }

    void generate(int cur, int n, int count, vector<string>& ans, string& res){
        if(count < 0) return;
        if(cur == n){
            ans.push_back(res);
            return;
        }
        
        res.push_back('(');
        count += 1;
        generate(cur + 1, n , count, ans, res);
        count -= 1;
        res.pop_back();

        res.push_back(')');
        count -= 1;
        generate(cur + 1, n , count, ans, res);
        count += 1;
        res.pop_back();
        
    }
    vector<string> generateParenthesis(int n) {
        int count = 0;
        string res;
        vector<string> ans;
        vector<string> final_ans;
        generate(0, 2*n, count, ans, res);
        for(auto str : ans){
            if(check(str))
                final_ans.push_back(str);
        }
        return final_ans;
    }
};






//! 将判断融入生成中
class Solution3 {
public:
    void generateans(int cur, int n, int left, int right, vector<string>& ans, string& res){
        if(cur == 2*n){
            ans.push_back(res);
            return;
        }

        if(left < n){
            res.push_back('(');
            left++;
            generateans(cur + 1, n , left, right,ans, res);
            left--;
            res.pop_back();
        }

        if(right < left){
            res.push_back(')');
            right++;
            generateans(cur + 1, n , left, right,ans, res);
            right--;
            res.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res;
        int left = 0;
        int right = 0;
        generateans(0 ,n ,left, right, ans, res);
        return ans;
    }
};