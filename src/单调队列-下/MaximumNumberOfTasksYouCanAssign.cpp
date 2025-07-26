// 你可以安排的最多任务数目
// 给你 n 个任务和 m 个工人。每个任务需要一定的力量值才能完成
// 需要的力量值保存在下标从 0 开始的整数数组 tasks 中，
// 第i个任务需要 tasks[i] 的力量才能完成
// 每个工人的力量值保存在下标从 0 开始的整数数组workers中，
// 第j个工人的力量值为 workers[j]
// 每个工人只能完成一个任务，且力量值需要大于等于该任务的力量要求值，即workers[j]>=tasks[i]
// 除此以外，你还有 pills 个神奇药丸，可以给 一个工人的力量值 增加 strength
// 你可以决定给哪些工人使用药丸，但每个工人 最多 只能使用 一片 药丸
// 给你下标从 0 开始的整数数组tasks 和 workers 以及两个整数 pills 和 strength
// 请你返回 最多 有多少个任务可以被完成。
// 测试链接 : https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
   int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
      sort(workers.begin(),workers.end());
      sort(tasks.begin(),tasks.end());
      int t_size = tasks.size();
      int w_size = workers.size();
      int l = 0;
      int r = min(t_size,w_size);
      int ans = 0;
      while(l <= r){
         int m = l + (r - l)/2;
         if(f(tasks,0,m - 1,workers,w_size - m,w_size - 1,pills,strength)){
            ans = max(ans , m);
            l = m + 1;
         }
         else{
            r = m - 1;
         }
      }
      return ans;
   }

   bool f(vector<int>& tasks, int t_l,int t_r, vector<int>& workers,int w_l,int w_r,int pills,int strength){
      vector<int> deque(t_r - t_l + 1);
      int h = 0;
      int t = 0;
      int cnt = 0;
      for(int i = w_l; i <= w_r; i++){
         while((t_l <= t_r) && (workers[i] >= tasks[t_l])){
            deque[t++] = tasks[t_l++];
         }
         if(h < t && workers[i] >= deque[h]){
            h++;
         }
         else{
            while((t_l <= t_r) && ((workers[i] + strength) >= tasks[t_l])){
               deque[t++] = tasks[t_l++];
            }
            if(h < t){
               t--;
               cnt++;
            }
            else{
               return false;
            }
         }
      }
      return cnt <= pills;
   }
};