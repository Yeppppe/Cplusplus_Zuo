// 二维差分模版(牛客)
// 测试链接 : https://www.nowcoder.com/practice/50e1a93989df42efb0b1dec386fb4ccc
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过


//! 注意二维差分的只能在0的基础上进行 不能在原数组的基础上进行

#include <iostream>
#include <vector>
using namespace std;

int main() {
   int n,m,q;
   int x1,y1,x2,y2,k;
   int count = 5;
   cin >> n >> m >> q;
   vector<vector<long long>> matrix (n+2,(vector<long long>(m+2,0)));
   vector<vector<long long>> matrix2 (n+2,(vector<long long>(m+2,0)));
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <=m; j++){
         cin >> matrix[i][j];
      }
   }

   while(q--){
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        matrix2[x1][y1] += k;
        matrix2[x1][y2+1] -=k;
        matrix2[x2+1][y1] -=k;
        matrix2[x2+1][y2+1] +=k;
   }
   for(int i = 1; i < n+1; i++){
      for(int j = 1; j < m+1; j++){
         matrix2[i][j] += matrix2[i-1][j] + matrix2[i][j-1] -matrix2[i-1][j-1];
         cout << matrix[i][j]+ matrix2[i][j]<< " ";
      }
      cout << endl;
   }
   
}
// 64 位输出请用 printf("%lld")

