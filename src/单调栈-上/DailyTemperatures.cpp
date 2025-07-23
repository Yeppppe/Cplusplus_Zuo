// 每日温度
// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer
// 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后
// 如果气温在这之后都不会升高，请在该位置用 0 来代替。
// 测试链接 : https://leetcode.cn/problems/daily-temperatures/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n = temperatures.size();
      vector<int> stack;
      stack.reserve(n);
      vector<int> ans(n,0);
      int cur;
      for(int i = 0; i < n; i++){
         while(!stack.empty() && temperatures[i] > temperatures[stack.back()]){                  //! 因为这个只需要输出最右侧的大于或小于的值，而不是两侧的，因此不需要修复阶段可以严格大于或小于 [2,3,3,3,3,1]可以测试下，右侧永远是对的但是左侧只有最左边的3才是对的
            cur = stack.back();
            stack.pop_back();
            ans[cur] = i - cur;
         }
         stack.push_back(i);
      }

      // for(int i = n - 2; i >= 0; i--){
      //    if(ans[i] != 0 && temperatures[i] == temperatures[ans[i]]){
      //       ans[i] = ans[i] + ans[i+ans[i]];
      //    }
      // }

      return ans;
      
   }
};

