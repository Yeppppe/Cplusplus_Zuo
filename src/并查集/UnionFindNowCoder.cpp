// 并查集模版(牛客)
// 路径压缩 + 小挂大
// 测试链接 : https://www.nowcoder.com/practice/e7ed657974934a30b2010046536a5372
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过



#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> head(1000002);
vector<int> sesize(1000002);
vector<int> stk(1000002);

int find_head(int a){
   int size = 0;
   while(head[a] != a){
      stk[size++] = a;
      a = head[a];
   }
   //* 扁平化
   while(size > 0){
      head[stk[--size]] = a;
   }
   return a;
}
bool is_sameunion(int a, int b){
   return find_head(a) == find_head(b);
}

void merge(int a, int b){
   int head_a = find_head(a);
   int head_b = find_head(b);
   if(head_a == head_b) return;

   if(sesize[head_a] <= sesize[head_b]){
      head[head_a] = head_b;
      sesize[head_b] += sesize[head_a];
   }
   else{
      head[head_b] = head_a;
      sesize[head_a] += sesize[head_b];
   }
}

int main() {
   int n,m;
   cin >> n >> m;
   int opt,a,b;
   for(int i = 1 ; i <= n; i++){
      head[i] = i;
      sesize[i] = 1;
   }
   for(int i = 0; i < m; i++){
      cin >> opt >> a >> b;
      if(opt == 1){
         string out = is_sameunion(a, b) ? "Yes" : "No";
         cout << out << endl;
      }
      else{
         merge(a , b);
      }
   }
   return 0;
}