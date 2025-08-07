// 小和问题
// 测试链接 : https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过



#include <iostream>
#include <vector>
#include <random>
using namespace std;
const int MAXN = 100001;
vector<int> help(MAXN);
vector<int> nums(MAXN);
long long merge(vector<int> &nums, int l , int m, int r){
   long long sum = 0;
   long long ans = 0;
   for(int i = l, j = m+1; j <= r; j++){
      while(i<=m && nums[i] <= nums[j]){                           //* 注意这个地方是while不是if
         sum += nums[i++];
      }
      ans += sum;
   }
   int a = l;
   int b = m+1;
   int i = l;
   while( a <= m && b <= r){
      help[i++] = nums[a] <= nums[b] ? nums[a++] : nums[b++];
   }
   while(a <= m){
      help[i++] = nums[a++];
   }
   while(b <= r){
      help[i++] = nums[b++];
   }
   for(int d = l; d <= r;d++){
      nums[d] = help[d];
   }
   return ans;
}


long long smallsum(vector<int> &nums, int l, int r){
   if(l == r) return 0;
   int m = (l + r)/2;
   return smallsum(nums,l,m) + smallsum(nums, m+1 , r) + merge(nums, l, m, r);
}


int main() {
   int N;
   cin >> N;
   for(int i = 0; i < N; i++){
      cin >> nums[i];
   }
   cout << smallsum(nums, 0 , N-1);
   return 0;
}