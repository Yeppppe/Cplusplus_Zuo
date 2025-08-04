// 斐波那契数
// 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列
// 该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
// 也就是：F(0) = 0，F(1) = 1
// F(n) = F(n - 1) + F(n - 2)，其中 n > 1
// 给定 n ，请计算 F(n)
// 测试链接 : https://leetcode.cn/problems/fibonacci-number/
// 注意：最优解来自矩阵快速幂，时间复杂度可以做到O(log n)
// 后续课程一定会讲述！本节课不涉及！

#include <iostream>
#include <unordered_map>
using namespace std;


//! 无脑暴力递归
class Solution {
private:
   unordered_map<int,int> map;
public:
// [](){ ... } 只是定义了一个 lambda 表达式（函数对象）
// [](){ ... }() 才是执行这个 lambda 表达式并返回结果
   Solution():map ( [](){
      unordered_map<int,int> m;
      m[0] = 0;
      m[1] = 1;
      return m;
   }() ){}

   int fib1(int n) {
      if(n == 0){
         return 0;
      }
      if(n == 1){
         return 1;
      }
      return fib1(n - 2) + fib1(n - 1);
   }

   int fib2(int n) {
      if(n == 0){
         return 0;
      }
      if(n == 1){
         return 1;
      }
      if(map.find(n) != map.end()){
         return map[n];
      }
      int ans = fib2(n - 2) + fib2(n - 1);
      map[n] = ans;
      return ans;
   }
};