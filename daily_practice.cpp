#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>
#include <vector>
#include <iostream>
using namespace std;

class ThreadPool{
private:
    mutex mtx_;
    condition_variable condition_;
    std::vector<thread> threads_;
    atomic_bool stop_;
    queue<function<void()>> taskqueue_;

public:
    ThreadPool(int nums);

    void addtask(function<void()> task);

    ~ThreadPool();
};





ThreadPool::ThreadPool(int nums){
    for(int i = 0; i < nums; i++){
        threads_.emplace_back([this]{
            cout << "id : " << this_thread::get_id() << endl;
            while(stop_ == false){
                std::function<void()> task;

                {
                    unique_lock<mutex> lock(mtx_);
                    
                    condition_.wait(lock, [this]{
                        return(stop_ == true) || (!taskqueue_.empty());
                    });

                    if(stop_ == true && taskqueue_.empty()) return;

                    task = std::move(taskqueue_.front());
                    taskqueue_.pop();
                }
                task();
            }
        });

    }
}


void ThreadPool::addtask(function<void()> task){
    {
        unique_lock<mutex> lock(mtx_);
        taskqueue_.push(task);
    }
    condition_.notify_one();
}



ThreadPool::~ThreadPool(){
    stop_ = true;
    condition_.notify_all();
    for(auto& th : threads_){
        th.join();
    }
}