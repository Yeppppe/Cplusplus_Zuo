// https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        // set<string> set;
        for(auto s : strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            // set.insert(tmp);
            map[tmp].emplace_back(s);
        }
        vector<vector<string>> ans;
        // for(auto s : set){
        //     ans.push_back(map[s]);
        // }
        for(auto it = map.begin(); it != map.end(); it++){         //! 注意这个遍历哈希表的方法
            ans.push_back(it -> second);              
        }
        return ans;
    }
};

