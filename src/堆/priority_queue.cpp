
#include <vector>
#include <queue>
using namespace std;
std::priority_queue<int> pq;  // 默认存储类型是大根堆（最顶部的元素是最大值）

//! 定义小根堆，方法1
std::priority_queue<int,vector<int>,greater<int>> min_heap;    //! 小根堆，小的元素上浮 


//! 定义小根堆，方法2
struct Compare{
   bool operator()(int a, int b){
      return a > b;     //! 小根堆：a > b时交换，让小元素上浮
   }
};



//! 优先级队列方法
// - push(value) : 插入元素到队列中（会自动调整堆结构）
// - top() : 返回队列中优先级最高的元素（不删除）
// - pop() ： 删除队列中优先级最高的元素(会自动调整堆结构)
// - empty(): 判断队列是否为空
// - size() : 返回队列中元素的个数


