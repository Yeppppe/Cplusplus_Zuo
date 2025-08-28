// https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
   vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> map;
      for(auto s : strs){
         string tmp = s;
         sort(s.begin(), s.end());
         map[s].push_back(tmp);
      }
      vector<vector<string>> ans;
      for(auto m : map){
         ans.push_back(m.second);
      }
      return ans;
   }
};

