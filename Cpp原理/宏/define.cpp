//! 预处理器对define只会做替换和拼接工作，并不会做语法检查

#define 标识符 替换表达式


//可以只定义一个空的宏定义,用来做定义选择
#define LARGE_ARRAY

#ifdef LARGE_ARRAY
    #define MAXSIZE 60
#else   
    #define MAX_SIZE 20
#endif


//! undef用来取消原来的定义
#if MAX_SIZE>50
    #undef MAX_SIZE
    #define MAX_SIZE 100
#else   
    #undef MAX_SIZE
    #define MAX_SIZE 15
#endif



//*  #define 标识符（参数列表）  替换表达式
//*  #define MUL(a, b) (a)*(b)
//*  define表达式在C++中可以被内联函数取代 inline int mul(int a, int b){return a*b}




//*  # 和 ##     #a会替换成以字符串便是的参数a 
#define PRINT(a) cout << #a << " = " << (a) << "";
float a = 3.0;
PRINT(a*2+3);
// 输出 > a*2+3 = 9      前面的a*2+3是#a的结果  a是最后表达式输出的结果

//!  双##是连接符
#define MEMBER(type,a) type m_##a
struct Demo{
    MEMBER(int, a);
    MEMBER(float, b);
};


//! 宏定义通常只在一行中，如果想使用多行的宏定义 需要使用 \ 作为每行结尾来串联每行

// 自带的宏标识符
//* 标识符   类型  说明
//* __LINE__ 整数 源文件行号
//* __FILE__ 字符串  源文件文件名
//* __DATE__ 字符串  编译日期
//* __TIME__ 字符串  编译时间
//* __cplusplus  整数   编译器版本号
