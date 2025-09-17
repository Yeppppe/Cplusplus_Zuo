#include <iostream>
#include <cstring>
//! 
//! size_t strlen(const char* str);   获取以参数 '\0' 结尾的C字符串
//! char* strcpy(char* dest, const char* src);     dest 目标字符数组，必须有足够空间存放 src 字符串（包括结尾的 '\0'）。
class String{
public:
    //默认构造函数
    String():data(nullptr){}

    // 构造函数
    String(const char* s){
        if(s){
            data = new char[strlen(s) + 1];       
            strcpy(data, s);
        }
        else{
            data = nullptr;
        }
    }

    String(const String& other){
        if(other.data){
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        else{
            data = nullptr;
        }
    }

    ~String(){
        delete[] data;
    }

    String& operator=(const String& other){
        if(this != &other){
            delete[] data;
            if(other.data){
                data = new char[strlen(other.data) + 1];
                strcpy(data, other.data);
            }
        }
        else{
            data = nullptr;
        }
        return *this;
    }

private:
    char* data;
};