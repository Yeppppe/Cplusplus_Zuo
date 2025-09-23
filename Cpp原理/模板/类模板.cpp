//! 函数模板

// template <class 标识符1, class 标识符2, ...> 函数声明;
// template <typename 标识符1, typename 标识符2, ...> 函数声明;
//! 其中用 class 或 typename 效果完全相同

//! 函数模板只是进行了实例化，并不是真正的函数，需要对函数模板进行实例化才能调用
template<class T>     
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 10, b = 13;
    swap<int> (a, b);     //! 直接通过函数来调用模板叫隐式实例化
}



//* 显示实例化
template<class T>
T max(T a, T b){
    return a > b ? a :b;
}

template float max<float>(float a, float b);    // 显示实例化的一种方式



//! 函数模板也可以有多个实例化参数  , 函数模板也可以重载
template <class T1, class T2>
T1 max(T1 a, T2 b){
    return a > b ? a : b;
}