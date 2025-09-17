// https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-100-liked

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int ans = 0;
        for(int l = 0, r = 0; r < s.size(); r++){
            if(map.count(s[r]) && map[s[r]] >= l){          //! 确保找的的字符在当前窗口内
                l = map[s[r]] + 1;
                map[s[r]] = r;
            }
            else{
                map[s[r]] = r;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

