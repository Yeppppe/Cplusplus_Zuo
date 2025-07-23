// 单调栈求每个位置左右两侧，离当前位置最近、且值严格小于的位置
// 给定一个可能含有重复值的数组 arr
// 找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置
// 返回所有位置相应的信息。
// 输入描述：
// 第一行输入一个数字 n，表示数组 arr 的长度。
// 以下一行输入 n 个数字，表示数组的值
// 输出描述：
// 输出n行，每行两个数字 L 和 R，如果不存在，则值为 -1，下标从 0 开始。
// 测试链接 : https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main() {
   int n;
   cin >> n;
   vector<int> arr(n);
   for(int i = 0; i < n; i++){
      cin >> arr[i];
   }
   vector<vector<int>> ans(n,vector<int>(2,-1));
   vector<int> stack;
   stack.reserve(n);
   for(int i = 0; i < n; i++){
      while(!stack.empty() && (arr[i] <= arr[stack.back()])){
         int cur = stack.back();
         stack.pop_back();
         ans[cur][0] = !stack.empty() ? stack.back() : -1;
         ans[cur][1] = i;
      }
      stack.push_back(i);
   }

   for(int i = stack.size()-1; i >= 0; i--){
      ans[stack[i]][0] = i - 1 >=0 ? stack[i-1]:-1;
      ans[stack[i]][1] = -1;
   }

   for(int i = n-2;i >=0; i--){
      if(ans[i][1] != -1 && arr[i] == arr[ans[i][1]]){
         ans[i][1] = ans[ans[i][1]][1];
      }
   }

   for(int i = 0; i < n; i++){
      cout << ans[i][0] << " " << ans[i][1] << endl;
   }

   return 0;
}






///   代码多次练习    ///

int main() {
   int n;
   cin >> n;
   vector<int> arr(n);
   for(int i = 0; i < n; i++){
      cin >> arr[i];
   }

   vector<vector<int>> ans(n,vector<int>(2,-1));
   vector<int> stack;
   stack.reserve(n);
   int cur;
   for(int i = 0; i < n; i++){
      while(!stack.empty() && arr[i] <= arr[stack.back()]){
         cur = stack.back();
         stack.pop_back();
         ans[cur][0] = !stack.empty() ? stack.back() : -1;
         ans[cur][1] = i;
      }
      stack.push_back(i);
   }

   // while(!stack.empty()){
   //    cur = stack.back();
   //    stack.pop_back();
   //    ans[cur][1] = -1;
   //    ans[cur][0] = !stack.empty() ? stack.back() : -1;
   // }
   for(int i = stack.size()-1; i >= 0; i--){                       //! 尽量不要一味的依赖容器的方法，将这个清算阶段的for循环 换成上面的while也对，但是会超时
      ans[stack[i]][0] = i - 1 >=0 ? stack[i-1]:-1;
      ans[stack[i]][1] = -1;
   }

   for(int i = n - 2; i >= 0; i--){
      if(ans[i][1] != -1 && arr[i] == arr[ans[i][1]]){
         ans[i][1] = ans[ans[i][1]][1];
      }
   }

   for(auto a : ans){
      cout << a[0] << " " << a[1] << endl;
   }
   return 0;
}