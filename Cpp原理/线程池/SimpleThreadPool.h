#ifndef SIMPLE_THREAD_POOL
#define SIMPLE_THREAD_POOL

#include <iostream>
#include <functional>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
// using namespace std;
class SimpleThreadPool{
public:
    //* 创建线程函数
    SimpleThreadPool(size_t threadCount);

    //* 向任务队列提交任务
    void enqueue(const std::function<void()>& func);

    //* 析构函数
    ~SimpleThreadPool();

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex mtx;
    std::condition_variable cv;
    bool stop;
};


inline SimpleThreadPool::SimpleThreadPool(size_t threadCount) : stop(false){
    for(int i = 0; i < threadCount; i++){
        workers.emplace_back([this]{
            while(true){                                    //! 这里为什么要用while true
                std::function<void()> task;                  //* std::function<void()> 表示不带参数，不带返回值的调用对象
                {
                    std::unique_lock<std::mutex> lock(this -> mtx);
                    cv.wait(lock, [this]{
                        return stop || !tasks.empty();
                    });                                    //! 后面的函数是为了防止虚假唤醒，如果函数被唤醒但是不满足条件 会继续睡眠回去

                    if(stop && tasks.empty()){       
                        return;             //! 退出线程
                    }

                    task = std::move(tasks.front());
                    tasks.pop();
                }
                task();
            }
        });
    }
}

inline void SimpleThreadPool::enqueue(const std::function<void()>& func){
    {
        std::unique_lock<std::mutex> lock(mtx);
        tasks.push(func);
    }
    cv.notify_one();
}


inline SimpleThreadPool::~SimpleThreadPool(){
    {
        std::unique_lock<std::mutex> lock(mtx);
        stop = true;
    }

    for(std::thread& worker : workers){
        if(worker.joinable()){
            worker.join();
        }
    }

}


#endif