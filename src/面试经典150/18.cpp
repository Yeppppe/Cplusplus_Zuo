// https://leetcode.cn/problems/integer-to-roman/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
   string intToRoman(int num) {
      unordered_map<int, string> map;
      map[1000] = "M";
      map[900] = "CM";
      map[500] = "D";
      map[400] = "CD";
      map[100] = "C";
      map[90] = "XC";
      map[50] = "L";
      map[40] = "XL";
      map[10] = "X";
      map[9] = "IX";
      map[5] = "V";
      map[4] = "IV";
      map[1] = "I";
      string ans;
      while(num >= 1000){
         num -= 1000;
         ans += "M";
      }
      while(num >= 900){
         num -= 900;
         ans += "CM";
      }
      while(num >= 500){
         num -= 500;
         ans += "D";
      }
      while(num >= 400){
         num -= 400;
         ans += "CD";
      }
      while(num >= 100){
         num -= 100;
         ans += "C";
      }
      while(num >= 90){
         num -= 90;
         ans += "XC";
      }
      while(num >= 50){
         num -= 50;
         ans += "L";
      }
      while(num >= 40){
         num -= 40;
         ans += "XL";
      }
      while(num >= 10){
         num -= 10;
         ans += "X";
      }
      while(num >= 9){
         num -= 9;
         ans += "IX";
      }
      while(num >= 5){
         num -= 5;
         ans += "V";
      }
      while(num >= 4){
         num -= 4;
         ans += "IV";
      }
      while(num >= 1){
         num -= 1;
         ans += "I";
      }
      return ans;
   }
};

