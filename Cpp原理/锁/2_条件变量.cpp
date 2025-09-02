#include <mutex>
#include <condition_variable>
#include <queue>
#include <optional>


template<class T>
class ThreadSafeQueue{
   std::mutex m;
   std::condition_variable cv;
   std::queue<T> q;
   bool closed = false;

public:
   void push(T x){
      {
         std::lock_guard<std::mutex> ls(m);
         if(closed) throw std::runtime_error("push on closed queue");
         q.push(std::move(x));
      }
      cv.notify_one();
   }

   std::optional<T> pop(){
      std::unique_lock<std::mutex> lk(m);
      cv.wait(lk, [&]{return closed || !q.empty(); });
      if(q.empty()) return std::nullopt;
      T x = std::move(q.front());  
      q.pop();
      return x;
   }

   void close(){
      {
         std::lock_guard<std::mutex> ls(m);
         closed = true;
      }
      cv.notify_all();
   }

};