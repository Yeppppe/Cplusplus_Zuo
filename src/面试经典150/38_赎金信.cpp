// https://leetcode.cn/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
   bool canConstruct(string ransomNote, string magazine) {
      vector<int> ran(26,0);
      vector<int> mag(26,0);
      for(auto s : ransomNote){
         ran[s - 'a']++;
      }
      for(auto s : magazine){
         mag[s - 'a']++;
      }
      for(int i = 0; i <26; i++){
         if(ran[i] > mag[i])
            return false;
      }
      return true;
   }
};
   