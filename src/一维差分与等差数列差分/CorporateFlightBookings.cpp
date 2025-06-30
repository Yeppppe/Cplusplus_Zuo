// 航班预订统计
// 这里有 n 个航班，它们分别从 1 到 n 进行编号。
// 有一份航班预订表 bookings ，
// 表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi]
// 意味着在从 firsti 到 lasti 
//（包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。
// 请你返回一个长度为 n 的数组 answer，里面的元素是每个航班预定的座位总数。
// 测试链接 : https://leetcode.cn/problems/corporate-flight-bookings/


// 解题思路：差分数组
// 差分数组是处理区间修改、单点查询问题的有效方法。其核心思想是：
// 对于原数组A，差分数组D满足：D[i] = A[i] - A[i-1]
// 当对原数组A的区间[l,r]进行+val操作时，只需要：D[l]+=val, D[r+1]-=val
// 通过差分数组的前缀和可以还原出原数组

//* 一维差分，把需要加工的数字一股脑都做完，之后直接给出完全操作后的结果

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
      vector<int> sum(n+2);        //* 仔细想一下这里为什么需要n+2个变量，首先第一个航班序号为1，因此n个至少就到n+1了 ，其中还需要再最右侧的下一个减去一个差分值，因此需要定义n+2个变量
      for(auto book : bookings){
         sum[book[0]] += book[2];
         sum[book[1]+1] -= book[2];
      }
      
      for(int i = 1; i < n+2; i++){      //* 求前缀和，从1开始到n+1索引
         sum[i] = sum[i-1] + sum[i];
      }

      vector<int> ans(n);
      for(int i = 1; i <= n; i++){      //* 因为只有n个数，因此n个航班之后的前缀和不必再进行累加
        ans[i-1] = sum[i];
      }
      return ans;
   }
};

