// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
int strStr(string haystack, string needle) {
   int m = haystack.size();
   int n = needle.size();
   for(int i = 0; i <= m - n; i++){
      if(check(haystack,i,i+n,needle)) return i;
   }
   return -1;
}

bool check(string haystack, int l, int r, string needle){
   for(int i = l; i < r; i++){
      if(haystack[i] != needle[i - l]){
         return false;
      }
   }
   return true;
}
};