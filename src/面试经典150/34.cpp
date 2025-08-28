// https://leetcode.cn/problems/substring-with-concatenation-of-all-words/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

//! 暴力迭代能解决 170/182 ！！！！ 而且是一遍成
class Solution {
public:
   vector<int> findSubstring(string s, vector<string>& words) {
      int n = words.size();
      int m = words[0].size();
      string sort_word;
      vector<int> ans;
      sort(words.begin(),words.end());
      for(auto w : words){
         sort_word += w;
      }
      int s_size = s.size(); 
      for(int i = 0; i <= s_size - n*m; i++){
         vector<string> tmp; 
         for(int j = i; j < i + m*n;j += m){
            tmp.push_back(s.substr(j,m));
            sort(tmp.begin(),tmp.end());
         }
         string t_string;
         for(auto t : tmp){
            t_string += t;
         }
         if(t_string == sort_word){
            ans.push_back(i);
         }
      }
      return ans;
   }
};


class Solution {
public:
   vector<int> findSubstring(string s, vector<string>& words) {
      vector<int> ans;
      if(words.empty()) return ans;

      int wordCount = words.size();
      int wordLen = words[0].size();
      int totalsize = wordCount*wordLen;
      int sSize = s.size();

      unordered_map<string,int> wordFreq;

      for(const string& w : words){
         wordFreq[w]++;
      }

      for(int i = 0; i < wordLen; i++){
         unordered_map<string, int> windowsFreq;
         int left = i;
         int right = i;
         int count = 0;
         while(right + wordLen <= sSize){
            string tmp = s.substr(right,wordLen);
            right += wordLen;
            if(wordFreq.find(tmp) != wordFreq.end()){
               windowsFreq[tmp]++;
               count++;
               while(windowsFreq[tmp] > wordFreq[tmp]){
                  string leftword = s.substr(left,wordLen);
                  windowsFreq[leftword]--;
                  left += wordLen;
                  count--;
               }

               if(count == wordCount){
                  ans.push_back(left);
               }
            }
            else{
               left = right;
               count = 0;
               windowsFreq.clear();
            }
         }
      }
      return ans;
   }
};

