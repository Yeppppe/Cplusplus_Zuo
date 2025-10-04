
//构造函数
//拷贝构造
//赋值函数
//析构函数

class string{
private:
    char* data;
    int len;

public:
    string():data(nullptr),len(0){

    }

    string(const string& other){
        len = other.len;
        if(other.data){
            data = new char(len + 1);
            strcpy(data, other.data);
        }
        else{
            data = nullptr;
        }
    }

    string(const char* s){
        if(s){
            int l = strlen(s);
            data = new char[len + 1];
            strcpy(data,s);
        }
        else{
            data = nullptr;
            len = 0;
        }
    }


    string& operator=(const string& other){
        if(this != &other){
            delete []data;
            int l = strlen(other.data);
            data = new char[l + 1];
            strcpy(data, other.data);
        }
        else{
            data = nullptr;
        }
        return *this;
    }


    ~string(){
        delete []data;
    }
}




//各个函数的理解

// 内存泄漏过多表现型
// 静态扫描工具原理，以及对比  背景 内容 优缺点
// 共享内存原理

