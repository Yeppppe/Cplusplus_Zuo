// https://leetcode.cn/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-interview-150
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s; 
        vector<vector<bool>> dp(n, vector<bool>(n));
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }

        int maxLen = 1;
        int begin = 0;
        for(int L = 2; L <= n; L++){
            for(int i = 0; i + L - 1< n; i++){
                int j = i + L - 1;
                if(s[i] != s[j]){
                    dp[i][j] = false;
                }
                else{
                    dp[i][j] = (L == 2) ? true : dp[i + 1][j - 1];
                    if(dp[i][j] && L > maxLen){
                        begin = i;
                        maxLen = L;
                    }
                }
            }
        }
        return s.substr(begin, maxLen);
    } 
};

