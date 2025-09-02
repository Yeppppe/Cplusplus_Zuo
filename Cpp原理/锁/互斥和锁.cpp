 //* std::mutex

#include <iostream>
#include <mutex>
#include <thread>
class Counter{
public:
   void inc(){
      counter_mutex.lock();
      m_count++;
      counter_mutex.unlock();
   }

   // int get(){return m_count; }   // 非同步写法
   //! 同步写法
   int get(){
      int temp;
      counter_mutex.lock();
      temp = m_count;
      counter_mutex.unlock();
      return temp;
   }

private:
   std::mutex counter_mutex;
   int m_count = 0;
};


int main(void){
   Counter counter;
   auto increase = [](Counter &counter){
      for(int i = 0; i < 10000000; i++)
         counter.inc();
   };
   std::thread th1(increase, std::ref(counter));
   std::thread th2(increase, std::ref(counter));

   th1.join();
   th2.join();

   std::cout << counter.get() << std::endl;
   return 0;
}


//! lock_guard  unique_lock   scoped_lock

//! 最简单的lock_guard函数
template <typename Mutex>
class lock_guard{
public:
   explicit lock_guard(Mutex &m): m_mutex(m)     //! explicit表示禁止隐式类型转换
   {
      m_mutex.lock();
   }

   lock_guard(Mutex& m, adopt_lock_t) noexcept:m_mutex(m){};   //! 用于接管已锁定的互斥量，noexcept表示一定不会抛出异常

   ~lock_guard(){
      m_mutex.unlock();
   }

   lock_guard(const lock_guard&) = delete;                //! 删除拷贝构造函数
   lock_guard &operator = (const lock_guard&) = delete;   //! 删除拷贝运算符，意味着不能将一个lock_guard对象赋值给另一个lock_guard对象
private:
   Mutex &m_mutex;
};

// lock_guard使用
class Counter_with_lock_guard{
public:
   void inc(){
      std::lock_guard lock(counter_mutex);
      m_count++;
   }

   int get(){
      std::lock_guard lock(counter_mutex);
      return m_count;
   }

private:
   std::mutex counter_mutex;
   int m_count = 0;
};







//! unique_lock 更加灵活 可以创建时暂时不锁定，使用过程中再锁定，也可以在使用中解锁然后再次锁定
class Counter_with_unique_lock{
public:
   void increase(int n){
      std::unique_lock lock(counter_mutex, std::defer_lock);     //! defer_lock参数表示延迟加锁，直到手动lock才会加锁
      while(n--){
         lock.lock();
         m_count++;
         lock.unlock();
      }
   }

   int get(){
      std::unique_lock lock(counter_mutex);        //! 在构造的时候自动直接调用counter_mutex.lock()  (若锁被占用，则会阻塞等待)
      return m_count;
   }
private:
   std::mutex counter_mutex;
   int m_count = 0;
};