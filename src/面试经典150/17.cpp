// https://leetcode.cn/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
   int romanToInt(string s) {
      unordered_map<char,int> map;
      map['I'] = 1;
      map['V'] = 5;
      map['X'] = 10;
      map['L'] = 50;
      map['C'] = 100;
      map['D'] = 500;
      map['M'] = 1000;
      int n = s.size();
      int value = 0;
      for(int i = 0; i < n; i++){
         if(i < n - 1 && map[s[i]] < map[s[i+1]]){
               value -= map[s[i]];
         }
         else{
               value += map[s[i]];
         }
      }
      return value;
   }
};