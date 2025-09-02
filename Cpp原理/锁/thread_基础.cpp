#include <thread>
#include <iostream>

void myfunc(double param1, double param2, double& result){
   result = param1 + param2;
}




struct myfunctor{
   void operator()(double param1, double param2){
      result = param1 + param2;
   }
   double result = 0;
};



class MyClass{
public:
   void sum(double param1, double param2){
      result = param1 + param2;
   }
   double result = 0;
};

int main(){
   double a = 1.1;
   double b = 3.2;
   double result = 0;

   std::thread thread1(myfunc,a,b,std::ref(result));

   myfunctor f;
   std::thread thread2(f,a,b);       //! 这种方式会拷贝一个f对象创建线程，因此如果打印f.result仍然是0。
 
   MyClass obj;
   std::thread thread3(MyClass::sum, &obj, a, b);    //! 这个线程传入的是obj的地址，因此随着线程进展 会改变对应obj对象的result的值

   double result2;
   std::thread thread4([&result2](double a, double b){result2 = a + b; }, a, b);

   thread1.join();
   thread2.join();
   thread3.join();
   thread4.join();

   return 0;
}


//! this_thread::get_id() : 获取当前的线程id
//! .joinable() 判断当前线程是否还正在执行或执行完毕但未被合并，只有这两种情况才能够调用.join方法等待进程

void hello(const std::string& name){
   std::cout << "Hello, " << name << ".[Thread Id = ]" << std::this_thread::get_id() << "]\n";
}


int main(){
   std::thread mythread(hello, std::string("World"));
   if(mythread.joinable())
      mythread.join();
   return 0;
}


//* thread对象只能移动赋值或移动构造
//* 不能拷贝赋值或拷贝构造
//* print函数是线程安全的 cout可能会造成输出混乱

