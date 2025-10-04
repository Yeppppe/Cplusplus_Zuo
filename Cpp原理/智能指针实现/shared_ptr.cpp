//* - 管理一个裸指针
//* - 引用计数
//* - 拷贝时增加引用计数
//* - 析构时减少引用技术,并在计数归零时释放内存

#include <iostream>

template<typename T>
class SharedPtr{
private:
    T* ptr;   
    int* ref_count;  // 引用计数
public:
    explicit SharedPtr(T* p = nullptr):ptr(p),ref_count(new int(1)){        //* explicit 禁止编译器进行隐式转换，只允许显示调用
        if(!p) *ref_count = 0;
    }

    SharedPtr(const SharedPtr& other): ptr(other.ptr), ref_count(other.ref_count){
        if(ptr){
            ++(*ref_count);
        }
    }

    SharedPtr& operator=(const SharedPtr& other){
        if(this != other){
            release();   //释放当前资源
            ptr = other.ptr;
            ref_count = other.ref_count;
            if(ptr){
                ++(*ref_count);
            }
        }
    }

    ~SharedPtr(){
        release();
    }

    T* get() const{
        return ptr;
    }

    T& operator*() const{            //* 重载运算符
        return *ptr;
    }

    T* operator->() const{           //! 这个函数不会改变函数对象
        return ptr;
    }

    int use_count() const{
        return *ref_count;
    }

private:
    void release(){
        if(ptr & --(*ref_count) == 0){
            delete ptr;
            delete ref_count;
            ptr = nullptr;
            ref_count = nullptr;
        }
    }
};