// https://leetcode.cn/problems/text-justification/description/?envType=study-plan-v2&envId=top-interview-150


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
   string fillwords(vector<string>& words, int bg, int ed, int maxWidth, bool lastline){
      int wordcount = ed - bg + 1;
      int spacecount = maxWidth + 1;
      for(int i = bg; i <= ed; i++){
         spacecount -= (words[i].size() + 1);
      }
      
      int spaceavg = (wordcount == 1) ? 1 : spacecount / (wordcount - 1);
      int spaceextra = (wordcount == 1) ? 0 :spacecount % (wordcount - 1);

      string ans;
      for(int i = bg; i < ed; i++){
         ans += words[i];
         if(lastline){
            ans += " ";
            continue;
         }
         int space = 1 + spaceavg + ((i - bg) < spaceextra ? 1 : 0);
         ans.append(space,' ');          
      }
      ans += words[ed];
      for(int i = ans.size(); i < maxWidth; i++){
         ans += " ";
      }
      return ans;
   }
public:
vector<string> fullJustify(vector<string>& words, int maxWidth) {
   vector<string> ans;
   int bg = 0;
   int ed = 0;
   int cnt = 0;
   int n = words.size();
   for(int i = 0; i < n; i++){
      cnt += words[i].size() + 1;
      if(i + 1 == words.size() || cnt + words[i+1].size() > maxWidth){
         ans.push_back(fillwords(words, bg , i, maxWidth, (i==words.size() - 1)));
         bg = i + 1;
         cnt = 0;
      }
   }
   return ans;
}
};
