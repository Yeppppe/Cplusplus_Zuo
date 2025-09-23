// 返回类型 (*函数指针名称) (参数列表)

#include <iostream>
using namespace std;
double mutiply(double a, double b){
    return a*b;
}

int main(void){
    double (*ptr)(double, double) = mutiply;
    double res = ptr(3.1, 5.2);
    cout << res << endl;
    return 0;
}






//! 定义函数别名
typedef double (*MyFuncTypePtr)(double, double);
int main2(void){
    MyFuncTypePtr ptr1 = mutiply;

    double res = ptr1(0.2, 1.5);
    cout << res << endl;
}

//* 或者
typedef double (MyFuncType)(double, double);
int main(void){
    MyFuncType* ptr2 = mutiply;
    double res = ptr2(0.2, 1.5);
    cout << res << endl;
}


//! 类成员函数指针  类对象的非静态成员函数要通过类对象才能调用
// 返回类型 (类名::*函数指针名称)(参数列表)；
class DemoClass{
public:
    double add(double a, double b){return a + b;}
    double multiply(double a, double b){return a*b;}
};

int main(void){
    double (DemoClass::*ptrMemberFunc)(double, double);
    ptrMemberFunc = DemoClass::add;

    DemoClass obj;
    double result = (obj.*ptrMemberFunc)(0.5, 1.9);
    cout << result << endl;                   //! 类的非静态成员函数必须要通过类对象才能调用

    return 0;
}