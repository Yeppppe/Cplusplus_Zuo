// 统计全1子矩形的数量
// 给你一个 m * n 的矩阵 mat，其中只有0和1两种值
// 请你返回有多少个 子矩形 的元素全部都是1
// 测试链接 : https://leetcode.cn/problems/count-submatrices-with-all-ones/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   int numSubmat(vector<vector<int>>& mat) {
      int row_num = mat.size();
      int col_num = mat[0].size();
      int ans = 0;
      vector<int> height(col_num,0);
      for(int i = 0; i < row_num; i++){
         for(int j = 0; j < col_num; j++){
            height[j] = mat[i][j] == 0 ? 0 : height[j] + 1;      //! 压缩数组的方式
         }
         ans += count_submatrices(height);
      }
      return ans;
   }

      // 比如
   //              1
   //              1
   //              1         1
   //    1         1         1
   //    1         1         1
   //    1         1         1
   //             
   //    3  ....   6   ....  8
   //   left      cur        i
   // 如上图，假设6位置从栈中弹出，6位置的高度为6(上面6个1)
   // 6位置的左边、离6位置最近、且小于高度6的是3位置(left)，3位置的高度是3
   // 6位置的右边、离6位置最近、且小于高度6的是8位置(i)，8位置的高度是4
   // 此时我们求什么？
   // 1) 求在4~7范围上必须以高度6作为高的矩形有几个？
   // 2) 求在4~7范围上必须以高度5作为高的矩形有几个？
   // 也就是说，<=4的高度一律不求，>6的高度一律不求！
   // 其他位置也会从栈里弹出，等其他位置弹出的时候去求！
   // 那么在4~7范围上必须以高度6作为高的矩形有几个？如下：
   // 4..4  4..5  4..6  4..7
   // 5..5  5..6  5..7
   // 6..6  6..7
   // 7..7
   // 10个！什么公式？
   // 4...7范围的长度为4，那么数量就是 : 4*5/2
   // 同理在4~7范围上，必须以高度5作为高的矩形也是这么多
   // 所以cur从栈里弹出时产生的数量 : 
   // (cur位置的高度-Max{left位置的高度,i位置的高度}) * ((i-left-1)*(i-left)/2)
   int count_submatrices(vector<int> height){
      int n = height.size();
      vector<int> stack;
      int count = 0;
      stack.reserve(n);
      for(int i = 0; i < n; i++){
         while(!stack.empty() && height[i] <= height[stack.back()]){
            int cur = stack.back();
            stack.pop_back();
            if(height[i] < height[cur]){                                    //! 注意这个条件，如果发现与预期相等，直接跨过这个区间，用后边的代替，会包含前面的情况
                  int left = stack.empty() ? -1:stack.back();
                  int left_num = left == -1 ? 0 : height[left];
                  count += (height[cur] - max(left_num,height[i])) * ((i - left - 1)*(i - left)/2);
            }
         }
         stack.push_back(i);          //! 不要忘记入栈
      }

      while(!stack.empty()){
         int cur = stack.back();
         stack.pop_back();
         int left = stack.empty() ? -1:stack.back();
         int left_num = left == -1 ? 0 : height[left];
         count += (height[cur] - max(left_num,0)) * ((n - left - 1)*(n - left)/2);
      }
      return count;
   }
};


