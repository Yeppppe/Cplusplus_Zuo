// 一开始1~n范围上的数字都是0，一共有m个操作，每次操作为(l,r,s,e,d)
// 表示在l~r范围上依次加上首项为s、末项为e、公差为d的数列
// m个操作做完之后，统计1~n范围上所有数字的最大值和异或和
// 测试链接 : https://www.luogu.com.cn/problem/P4231
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过

// 初始有一个长度为n的数组，所有元素都是0
// 进行m次操作，每次操作为(l,r,s,e,d)，表示在区间[l,r]上依次加上一个等差数列
// 首项为s
// 末项为e
// 公差为d=(e-s)/(r-l)
// 所有操作完成后，求数组的最大值和所有元素的异或和

//* 洛谷登录不上，这里只记录等差数列差分的基本算法
//! ios::sync_with_stdio(false);
//* 默认情况下，C++的iostream库（cin、cout）与C的stdio库（printf、scanf）是同步的，这确保了它们混合使用时的正确性
//* 设置为false后，关闭这种同步机制，使cin/cout的速度显著提升
//* 缺点：关闭同步后，不能在同一段代码中混用C风格输入输出（如printf、scanf）和C++风格输入输出（如cin、cout），否则可能导致输出顺序混乱


//! cin.tie(nullptr);
//* 默认情况下，cin与cout是绑定的，这意味着每次使用cin前会自动刷新cout的缓冲区
//* 解除这种绑定后，cin操作前不会自动刷新cout，减少了不必要的刷新操作
//* 这在处理大量输入输出时能显著提高性能


//! c++ <algorithm>  fill(first, last, value);
// fill(arr, arr + n + 3, 0);
// arr：数组的起始地址（指向第一个元素）
// arr + n + 3：数组中第 n+3 个元素之后的地址（不包含该元素）
// 0：要填充的值

#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 10000005;
long long arr[MAXN];
int n,m;
void set(int l, int r, int s, int e, int d){
   arr[l] += s;
   arr[l+1] += d-s;
   arr[r+1] -= d-s;
   arr[r+2] += e;
}


void build(){
   for(int i=1; i<=n; i++){
      arr[i] += arr[i - 1];
   }
   for(int i=1; i <= n ;i++){
      arr[i] += arr[i - 1];
   }
}


int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   while(cin >> n >> m){
      fill(arr,arr+3,0);

      for (int i = 0; i < m; i++) {
            int l, r, s, e;
            cin >> l >> r >> s >> e;
            int d = (e - s) / (r - l);
            set(l, r, s, e, d);
        }
        
        build();
        
        long long max_val = 0, xor_sum = 0;
        for (int i = 1; i <= n; i++) {
            max_val = max(max_val, arr[i]);
            xor_sum ^= arr[i];
        }
        
        cout << xor_sum << " " << max_val << endl;
   }
}

