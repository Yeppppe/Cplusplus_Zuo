#include "BigInteger.h"
#include <iostream>
#include <algorithm>

BigInteger& BigInteger::operator = (long long num){
    m_bits.clear();
    while(num>0){
        m_bits.push_back(num%BASE);
        num /= BASE;
    }
    return *this;
}

//* sscanf : 从一个字符串中读取格式化输入（但必须是c风格字符串，如果是string需要使用.c_str()进行转换）
//* .substr(start,end-start): 是string类的一个成员函数，用来提取string的字串，字串索引[start,end) 
BigInteger& BigInteger::operator = (const std::string& num_string){
    m_bits.clear();
    int length = num_string.size();
    int bit,group = (length-1)/WIDTH+1;
    for(int i=0;i<group;i++){
        int end = length - i*WIDTH;
        int start = std::max(0,end - WIDTH);
        sscanf(num_string.substr(start,end-start).c_str(),"%d",&bit);
        m_bits.push_back(bit);
    }    
    return *this;
}

BigInteger::BigInteger(long long num){
    *this = num;
}

BigInteger::BigInteger(const std::string num_string){
    *this = num_string;
}

BigInteger BigInteger::operator + (const BigInteger& rhs) const{
    BigInteger result;
    result.m_bits.clear();
    int carry = 0;
    for(int i = 0;;i++){
        if(i >=m_bits.size() && i>=rhs.m_bits.size() && carry==0)
            break;
        int num = carry;
        if(i<m_bits.size()) 
            num+=m_bits[i];
        if(i<rhs.m_bits.size()) 
            num+=rhs.m_bits[i];
        result.m_bits.push_back(num%BASE);
        carry = num/BASE;
    }
    return result;
}


BigInteger& BigInteger::operator += (const BigInteger& rhs){
    *this = *this+rhs;
    return *this; 
}


BigInteger BigInteger::operator - (const BigInteger& rhs) const{
    BigInteger result;
    result = (*this>= rhs) ? sub(*this,rhs) : sub(rhs,*this);
    return result;
}

BigInteger& BigInteger::operator -= (const BigInteger& rhs){
    *this = *this-rhs;
    return *this; 
}

// * vector.resize()会直接改变当前vector内元素的数量，若new_size大于原size则增加元素数量，否则则减少元素数量
//* 注意for循环下要用size_t 用int可能会导致位数不够？
BigInteger BigInteger::operator * (const BigInteger& rhs) const{
    BigInteger result;
    result.m_bits.clear();
    result.m_bits.resize(m_bits.size()+rhs.m_bits.size(),0);
    for(size_t i =0; i < m_bits.size(); i++){
        for(size_t j =0; j < rhs.m_bits.size(); j++){
            int num = m_bits[i]*rhs.m_bits[j];
            result.m_bits[i+j]+=num;
        }
    }
    formatBits(result);
    removeHighestZero(result);
    return result;
}

BigInteger& BigInteger::operator *= (const BigInteger& rhs){
    *this = *this * rhs;
    return *this;
}

BigInteger BigInteger::operator / (const BigInteger& rhs) const{
    if(rhs == BigInteger(0))
        throw std::runtime_error("Divisor cannot be 0!");
    
    BigInteger tmp = *this;
    return divide(tmp,rhs);
}

//* 这个很妙 得自己思考下
BigInteger BigInteger::divide(BigInteger &lhs, const BigInteger &rhs) {
    if (lhs < rhs) {
        return BigInteger(0);
    }
    if (rhs == BigInteger(0)) {
        throw std::runtime_error("Division by zero");
    }
    
    BigInteger result;
    int maxSize = lhs.m_bits.size() - rhs.m_bits.size();

    // 确保 maxSize 不为负数
    if (maxSize < 0) {
        return BigInteger(0);
    }

    BigInteger multiple, product;
    while (lhs >= rhs && maxSize >= 0) {
        multiple.m_bits.clear();
        multiple.m_bits.resize(maxSize + 1, 0);
        if (maxSize >= 0 && maxSize < multiple.m_bits.size()) {
            multiple.m_bits[maxSize] = 1;
        } else {
            break;
        }
        
        product = rhs * multiple;
        if (product > lhs) {
            maxSize--;
            continue;
        }

        while (lhs >= product) {
            lhs -= product;
            result += multiple;
        }
        maxSize--;
    }
    return result;
}


void BigInteger::formatBits(BigInteger &num){
    int carry = 0;
    for(int i = 0; i < num.m_bits.size(); i++){
        int tmp = num.m_bits[i] + carry;
        num.m_bits[i] = tmp % BASE;
        carry = tmp / BASE;
    }
    while(carry!=0){
        num.m_bits.push_back(carry % BASE);
        carry = carry/BASE;
    }
}

void BigInteger::removeHighestZero(BigInteger &num)
{    
	while (num.m_bits.size() > 1 && num.m_bits.back() == 0)        
		num.m_bits.pop_back();
}

//* 静态成员函数在类外定义是无需再加上static
BigInteger BigInteger::sub(const BigInteger &lhs,const BigInteger &rhs){
    BigInteger result;
    result.m_bits.clear();
    for(int i=0,carry=0;;i++){
        int num = 0;
        if(i>=lhs.m_bits.size()&&i>=rhs.m_bits.size()&&carry==0)
            break;
        if(i<lhs.m_bits.size())
            num += lhs.m_bits[i];
        if(i<rhs.m_bits.size())
            num -= rhs.m_bits[i];
        num+=BASE;
        result.m_bits.push_back(num%BASE);
        carry = num/BASE - 1;
    }
    removeHighestZero(result); 
    return result;
}

bool BigInteger::operator > (const BigInteger& rhs) const{
    if(m_bits.size()!=rhs.m_bits.size()){
        return m_bits.size()>rhs.m_bits.size();
    }

    for(int i = m_bits.size()-1;i>=0;i--){
        if(m_bits[i]!=rhs.m_bits[i])
            return m_bits[i]>rhs.m_bits[i];
    }
    return false;
}


//* vector容器可以直接比较！
bool BigInteger::operator == (const BigInteger& rhs) const{
    // if(m_bits.size()!=rhs.m_bits.size()){
    //     return false;
    // }
    // for(int i = m_bits.size()-1;i>=0;i--){
    //     if(m_bits[i]!=rhs.m_bits[i])
    //         return false;
    // }
    // return true;
    return m_bits == rhs.m_bits;  
}

// bool BigInteger::operator != (const BigInteger& rhs) const{
//     return !(*this == rhs);
// }

bool BigInteger::operator != (const BigInteger &rhs) const
{    
	return m_bits != rhs.m_bits;
}

bool BigInteger::operator >= (const BigInteger& rhs) const{
    return (*this > rhs || *this == rhs);
}

//* 注意代码复用！ 避免重复造轮子
bool BigInteger::operator < (const BigInteger& rhs) const{
    return !(*this >= rhs);
}

bool BigInteger::operator <= (const BigInteger& rhs) const{
    return (*this<rhs || *this==rhs);
}



//* sprintf(char* buffer , const char* format, ...)  将...以format(需要是c字符串)转换到buffer中
std::ostream& operator <<(std::ostream& out,const BigInteger& nums){
    static std::string format = "%0" + std::to_string(BigInteger::WIDTH) + "d"; 
    out << nums.m_bits.back();
    for(int i = nums.m_bits.size()-2;i>=0;i--){
        char buf[5];
        sprintf(buf,format.c_str(),nums.m_bits[i]);
        out << buf;
    }
    return out;
}


std::istream& operator >> (std::istream& in, BigInteger& nums){
    std::string instr;
    //* if(!(in >> instr))用于检查输入流读取是否失败
    if(!(in >> instr))
        return in;
    nums = instr;
    return in;
}
