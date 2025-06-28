// https://www.nowcoder.com/practice/36fb0fd3c656480c92b569258a1223d5

// 描述
// 给定一个无序数组arr, 其中元素可正、可负、可0。给定一个整数k，求arr所有子数组中累加和为k的最长子数组长度
// 输入描述：
// 第一行两个整数N, k。N表示数组长度，k的定义已在题目描述中给出
// 第二行N个整数表示数组内的数

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> nums;
int main() {
   int N,k;
   cin >> N >> k;
   while(N--){
   int tmp;
   cin >> tmp;
   nums.push_back(tmp);
   }
   
   unordered_map<int,int> map;
   int sum = 0;
   map[0] = -1;
   int ans = 0;        //* 牛客上一定要设置初始值
   for(int i = 0; i < nums.size(); i++){
      sum += nums[i];
      if(map.find(sum - k) != map.end()){
         ans = max(ans,i-map[sum-k]);
      }
      if(map.find(sum) == map.end())
         map[sum] = i;
   }

   cout << ans;
   return 0;
}
