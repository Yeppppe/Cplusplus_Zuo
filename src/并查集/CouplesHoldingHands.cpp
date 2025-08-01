// 情侣牵手
// n对情侣坐在连续排列的 2n 个座位上，想要牵到对方的手
// 人和座位由一个整数数组 row 表示，其中 row[i] 是坐在第 i 个座位上的人的ID
// 情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2n-2, 2n-1)
// 返回 最少交换座位的次数，以便每对情侣可以并肩坐在一起
// 每次交换可选择任意两人，让他们站起来交换座位
// 测试链接 : https://leetcode.cn/problems/couples-holding-hands/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
   vector<int> father;
   int set;
public:
   int minSwapsCouples(vector<int>& row) {
      int size = row.size();
      build(size/2);
      set = size/2;
      for(int i = 0; i < size; i += 2){
         Union(row[i]/2, row[i+1]/2);
      }
      return size/2 - set;
   }
   
   void build(int m){
      father.resize(m);
      for(int i = 0; i < m; i++){
         father[i] = i;
      }
   }

   int find(int i){
      if(i != father[i]){
         father[i] = find(father[i]);
      }
      return father[i];
   }

   void Union(int a, int b){
      int fa = find(a);
      int fb = find(b);
      if(fa != fb){
         father[fa] = fb;  // 让根节点fa指向根节点fb
         set--;
      }
   }
};