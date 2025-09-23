// * std::function
#include <iostream>
#include <functional>
using namespace std;
template <class R, class... Args >           //! class... 表示这是一个可变模板参数
class function<R(Args...)>;      //! 第一个R是返回类型  Args...表示可变模板参数

function<R<Arg...>> fname = target;         //其中target是要封装的函数指针或函数对象



// 封装类的成员函数，参数变量的第一个要是类的引用
struct Linear{
    Linear(float k, float b):k_(k), b_(b){}
    float f(float x){return k_*x + b_;}
    float k_, b_;
};

int main(){
    //* 封装类成员函数
    std::function<float(Linear&, float)> mf = &Linear::f;
    Linear l(1.2, 2.3);
    float res = mf(l, 5);
    cout << res << endl;

    //* 封装类成员变量
    std::function<float(Linear&)> k = &Linear::k_;
    cout << k(l) << endl;    //* 访问l的类成员函数k

}





//* 类型擦除模式：可以使用单个通用接口来使用各种具体类型，例子如下
#include<map>
float add (float a, float b){
    return a + b;
}

struct Substract{
    float operator()(float a, float b){
        return a - b;
    }
};

int main2(void){
    std::map<char, std::function<double(double, double)>> calculator{
        {'+', add},
        {'-',Substract()},
        {'*',[](double a, double b) -> double {return a*b;}}
    };

    cout << calculator['+'](12.0, 13) << endl;
    cout << calculator['-'](12.0, 13) << endl;
    cout << calculator['*'](12.0, 13) << endl;
    return 0;
}


//* memfn 用来直接封装类成员函数
struct Foo{
    float w;
    float calculator(float a, float b){ return 2 * a + w* b;}
    Foo& operator += (float a){
        w+= a;
        return *this;
    }
    void print(){
        std::cout << "w = " << w << endl;
    }
};

int main3(){
    Foo f{1.0};

    auto memfn = std::mem_fn(&Foo::calculator);
    float res = memfn(f, 2.0, 3.0);
    cout << "res = " << res << endl;
    auto op_add_assign = mem_fn(&Foo::operator+=);
    auto f2 = op_add_assign(f, 2.0);
    f2.print();
}


//! ================================================================================================
//* std::bind 是一个函数模板，用来生成一个函数调用的转发包装器(也就是一个函数对象),调用这个包装器就相当于调用它所包装的函数或者对象f，并使用args作为函数的参数
template <class F, class... Args>
bind(F&& f, Args&&... args);



using namespace std::placeholders;

int sum(int a, int b, int c){
    return a + b + c;
}

int main3(){
    auto f = std::bind(sum, 1, 2, 3);
    int res = f();
    cout << ", res = " << res << endl;


    auto f2 = std::bind(sum, 1, _1, 2);    // placeholders中使用 _1, _2来代替被绑定的实际参数
    int res = f(2);
    cout << "res = " << res;


    //* std::bind 默认是值传入的，如果想要引用传入，则要使用 std::cref(n) 来修饰变量
    int n = 6;
    auto f3 = std::bind(sum, 1, 2, std::cref(n));
    n = 11; 
    int res = f3();     //! 使用引用传入，此时n的值为11 并调用f3函数

    return 0;

}

