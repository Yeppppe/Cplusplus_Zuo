#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>
#include <chrono>

std::queue<std::function<void()>> taskQueue;
std::mutex mtx;
std::condition_variable cv;
bool finish = false;


void producer(int id){
    for(int i = 0; i < 3; i++){
        {
            std::lock_guard<std::mutex> lock(mtx);                //! lock_guard只是简单的控制临界区范围，开销小，但是没有unique_lock功能多

            taskQueue.push([id, i](){
                std::cout << "任务来自生产者" << id
                          << ", 任务编号 "  << i
                          << ", 执行线程ID: " << std::this_thread::get_id() << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            });
            cv.notify_one(); //通知一个消费者
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}


void consumer(int id){
    while(true){
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(mtx);                   //! unique_lock支持立即锁，延迟锁，以及条件变量wait   如果只是简单的临界区固定，用lock_guard即可，如果需要wait则需要使用unique_lock 
            cv.wait(lock, []{return !taskQueue.empty() || finish;});       //! 只有当队列为空 且finish = false的时候，才会挂起
            
            if(!taskQueue.empty()){
                task = std::move(taskQueue.front());
                taskQueue.pop();
            }
            else if(finish){
                break;     //! 队列为空 同时 finish = true 表示线程模型结束
            }
        }

        if(task){
            std::cout << " 消费者 " << id << " 开始执行任务" << std::endl;
            task();
        }
    }
}

int main(){
    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;

    for(int i = 1; i <= 2; i++){
        producers.emplace_back(producer, i);     // emplace_back会直接使用prodecer 和 i 直接创建一个thread对象并添加到prodecers中
    }

    for(int i = 1; i <= 3; i++){
        consumers.emplace_back(consumer, i);
    }

    for(auto& p : producers){        //! thread对象不可拷贝， 因此必须使用引用！！！
        p.join();
    }

    {
        std::lock_guard<std::mutex> lock(mtx);
        finish = true;
    }
    cv.notify_all();

    for(auto& c : consumers){
        c.join();
    }

    std::cout << "所有任务完成" << std::endl;
    return 0;
}

