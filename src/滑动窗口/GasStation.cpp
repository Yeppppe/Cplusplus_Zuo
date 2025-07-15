// 加油站
// 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
// 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升
// 你从其中的一个加油站出发，开始时油箱为空。
// 给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周
// 则返回出发时加油站的编号，否则返回 -1
// 如果存在解，则 保证 它是 唯一 的。
// 测试链接 : https://leetcode.cn/problems/gas-station/

#include <iostream>
#include <vector>
using namespace std;


//! 暴力解法直接超时。不过应该是对的，a了34/36
class Solution {
public:
   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      vector<int> add(gas.size(),0);
      for(int i =0; i<add.size(); i++){
         add[i] = gas[i] - cost[i];
      }
      int sum = 0;
      int time = 0;
      int size = add.size();
      for(int i = 0; i < size; i++){
         time = size;
         sum = 0;
         while(time--){
            sum += add[(i+ size - time -1)%size];
            if(sum < 0) break;
         }
         if(sum >= 0 ) return i;
      }
      return -1;
   }
};



class Solution {
public:
   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int size = gas.size();
      for(int i =0; i < size; i++){
         int sum = 0;
         for(int k = 0; k < size; k++){
            sum += gas[(i+k)%size] - cost[(i+k)%size];
            if(sum < 0){
               i = i+k;
               break;
            }
         }
         if(sum >= 0) return i;
      }
      return -1;
   }
};



