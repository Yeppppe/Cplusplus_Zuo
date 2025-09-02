#include <shared_mutex>
#include <string>
#include <unordered_map>
class RWMap{
   mutable std::shared_mutex m;
   std::unordered_map<int, std::string> mp;

public:
   std::string get(int k) const{
      std::shared_lock lk(m);                       // 读锁，可并发
      if(auto it = mp.find(k); it != mp.end()){
         return it -> second;
      }
      return {};
   }

   void set(int k, std::string v){
      std::unique_lock lk(m);                      // 写锁，独占
      mp[k] = std::move(v); 
   }
};

