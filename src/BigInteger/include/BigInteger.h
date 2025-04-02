#pragma once
#include <iostream>
#include <string>
#include <vector>

/*
    存储任意大小的非负整数
    构造函数 接收long long 和 string类型
    重载运算符 + - * / = += -+ *= /= % %= > >= < <= == !=
    重载流运算符 << >>
*/

class BigInteger{
    friend std::ostream& operator << (std::ostream& out,const BigInteger& nums);
    friend std::istream& operator >> (std::istream& in, BigInteger& nums);
public:
    //* 同时还取代了默认构造函数 多个自定义构造函数只能够有一个含有参数默认值，不然会引发编译错误，因为默认构造函数会有歧义
    BigInteger(long long num=0);
    BigInteger(const std::string num_string);

    BigInteger& operator = (long long num);
    BigInteger& operator = (const std::string& num_string);

    //* 加法是一个二元运算符
    BigInteger operator + (const BigInteger& rhs) const;
    //* += 将运算后的结果重新返回到*this上 
    BigInteger& operator += (const BigInteger& rhs);

    BigInteger operator - (const BigInteger& rhs) const;
    BigInteger& operator -= (const BigInteger& rhs);

    BigInteger operator * (const BigInteger& rhs) const;
    BigInteger& operator *= (const BigInteger& rhs);

    BigInteger operator / (const BigInteger& rhs) const;
    BigInteger& operator /= (const BigInteger& rhs);

    BigInteger operator % (const BigInteger& rhs) const;
    BigInteger& operator %= (const BigInteger& rhs);

    bool operator > (const BigInteger& rhs) const;
    bool operator >= (const BigInteger& rhs) const;

    bool operator < (const BigInteger& rhs) const;
    bool operator <= (const BigInteger& rhs) const;

    bool operator == (const BigInteger& rhs) const;
    bool operator != (const BigInteger& rhs) const;

//* pimpl惯用法(Point to Implementation)指向实现的指针 的缩写，将类的实现细节从头文件中分离，隐藏在.cpp中
private:
    //* 假设lhs > rhs
    static BigInteger sub(const BigInteger &lhs,const BigInteger &rhs);

    //* 长除法
    static BigInteger divide(BigInteger &lhs, const BigInteger &rhs);

    //* 去掉最高位的0
    static void removeHighestZero(BigInteger &num);

    //* 格式化各数位，使其符合进制
    static void formatBits(BigInteger &num);

private:
    std::vector<int> m_bits;
    static const int BASE = 10000;
    static const int WIDTH = 4;

}
;


std::ostream& operator << (std::ostream& out,const BigInteger& nums);
std::istream& operator >> (std::istream& in, BigInteger& nums);