// 每个元音包含偶数次的最长子字符串
// 给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度
// 每个元音字母，即 'a'，'e'，'i'，'o'，'u'
// 在子字符串中都恰好出现了偶数次。
// 测试链接 : https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/

// 核心思路
// 这个问题采用了状态压缩 + 前缀和 + 哈希表的思路：
// 状态压缩：
// 使用一个5位的二进制数表示5个元音字母的奇偶性状态
// 每一位对应一个元音字母：0表示出现偶数次，1表示出现奇数次
// 例如：00101表示'a'和'e'出现偶数次，'i'和'u'出现奇数次，'o'出现偶数次
// 状态转移：
// 当遇到一个元音字母时，翻转其对应位的状态（偶变奇，奇变偶）
// 使用异或操作(^)来实现状态翻转
// 前缀思想：
// 维护从开始到当前位置的所有元音字母出现次数的奇偶性状态
// 如果两个位置的状态相同，说明它们之间的子字符串中所有元音都出现了偶数次

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
   int findTheLongestSubstring(string s) {
      int ans = 0;
      unordered_map<int,int> map;
      map[0] = -1;
      int status = 0;
      for(int i = 0; i < s.size(); i++){
         if(move(s[i]) != -1){
            status ^= 1 << move(s[i]);
         }
         if(map.find(status) != map.end()){
            ans = max(ans , i - map[status]);
         }
         else{
            map[status] = i;
         }
      }
      return ans;
   }

   int move(char s){
      switch(s){
         case 'a' : return 1;
         case 'e' : return 2;
         case 'i' : return 3;
         case 'o' : return 4;
         case 'u' : return 5;
         default: return -1;
      }
   }
};