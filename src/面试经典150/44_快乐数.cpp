// https://leetcode.cn/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
   int bs(int n){
      int sum = 0;
      while(n > 0){
         int cur = n % 10;
         sum += cur * cur;
         n = n / 10;
      }
      return sum;
   }
   bool isHappy(int n) {
      int slow = n, fast = n;
      slow = bs(slow);
      fast = bs(fast);
      fast = bs(fast);
      while(slow != fast){
         slow = bs(slow);
         fast = bs(fast);
         fast = bs(fast);
      }
      return slow == 1;
   }
};