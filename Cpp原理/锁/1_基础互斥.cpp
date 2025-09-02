#include <mutex>

struct Counter{
   std::mutex m;
   long long v = 0;
   void inc(){
      std::lock_guard<std::mutex> lk(m);    //RAII,异常安全
      ++v;
   }

   long long get(){
      std::lock_guard<std::mutex> ls(m);
      return v;
   }
};