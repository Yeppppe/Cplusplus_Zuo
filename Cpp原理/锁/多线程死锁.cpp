#include <iostream>
#include <mutex>

//! 常见死锁
class DoSomething{
public:
   int func1(){
      std::lock_guard lock(mtx);
      count*=2;
      func2();
      return count;
   }

   void func2(){
      std::lock_guard(mtx);
      count++;
   }

private:
   std::mutex mtx;
   int count = 0;
};


int main(){
   DoSomething op;
   int result = op.func1();     //! 只有一个线程 直接死锁
   return 0;
}



//! 解决最基本的死锁 mutex -> recursive_mutex mtx;
class DoSomething_with_recursive_mutex{
public:
   int func1(){
      std::lock_guard lock(mtx);
      count *= 2;
      func2();
      return count;
   }

   void func2(){
      std::lock_guard(mtx);
      count++;
   }

private:
   std::recursive_mutex mtx;          //* std::recursive_mutex原理，当对其进行重复加锁的时候不会阻塞，直到所有加锁全都释放后才会将其释放。
   int count = 0;
};



//! 活锁
//* 死锁2 两个程序没按照相同的顺序获得互斥量
//* 程序1获得mutex1&&程序2获得mutex2 -> 然后程序1尝试获得mutex2&&程序2尝试获得mutex1 就会导致死锁
//* 解决方法可以使用try_lock_for() 当获取锁超时的时候，均进行释放，形成一种活锁状态（即形成死锁就将锁全部释放）
//* 注意获取锁的顺序 可以避免这种死锁现象
//! 使用std::lock来避免这种死锁

//* std::lock是 C++ 标准库提供的一个特殊函数，用于同时获取多个互斥锁，其核心作用是：
//* 保证以 “原子操作” 的方式获取所有锁，且内部会自动处理锁的获取顺序，避免因线程间获取顺序不一致导致的死锁。
{
   std::mutex mtx;
   std::mutex cout_mtx
   void func1(){
      std::lock(mtx1, cout_mtx);
      std::lock_guard lock1(mtx1, std::adopt_lock);         //! adopt_lock相当于一个标记 用来告诉lock_guard这个锁已经被提前获取了,只需要接管它的声明周期，不需要再调用lock();
      std::lock_guard lock2(cout_mtx, std::adopt_lock);
      count++;
      std::cout << "Count = " << count << std::endl;
   }

   void func2(){
      std::lock(cout_mtx, mtx1);

      std::lock_guard lock1(cout_mtx, std::adopt_lock);
      std::lock_guard lock2(mtx1, std::adopt_lock);
      count++;
      std::cout << "Count = " << count << std::endl;
   }

}

//* scoped_lock类 scoped_lock会在构造时自动调用std::lock函数，在析构时自动释放
class DemoClass{
private:
   std::mutex mtx1;
   std::mutex cout_mtx;
   count = 0;
public:
   void func1(){
      std::scoped_lock lock(mtx1,cout_mtx);
      count++;
      std::cout << "Count = " << count << std::endl;
   }

   void func2(){
      std::scoped_lock lock(cout_mtx, mtx1);
      count*=2;
   }
};