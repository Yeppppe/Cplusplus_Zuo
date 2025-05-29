#include <iostream>
#include <string>

// 使用C++处理大数的方法计算
int f1(long long a, long long b, long long c, long long d, int mod) {
    // 由于C++没有内置BigInteger，使用__int128代替（如果支持）
    __int128 o1 = a;  // a
    __int128 o2 = b;  // b
    __int128 o3 = c;  // c
    __int128 o4 = d;  // d
    __int128 o5 = o1 + o2;  // a + b
    __int128 o6 = o3 - o4;  // c - d
    __int128 o7 = o1 * o3;  // a * c
    __int128 o8 = o2 * o4;  // b * d
    __int128 o9 = o5 * o6;  // (a + b) * (c - d)
    __int128 o10 = o7 - o8;  // (a * c - b * d)
    __int128 o11 = o9 + o10;  // ((a + b) * (c - d) + (a * c - b * d))
    
    // ((a + b) * (c - d) + (a * c - b * d)) % mod
    __int128 o12 = o11 % mod;
    
    if (o12 < 0) {
        // 如果是负数那么+mod返回
        return static_cast<int>(o12 + mod);
    } else {
        // 如果不是负数直接返回
        return static_cast<int>(o12);
    }
}

// 计算 ((a + b) * (c - d) + (a * c - b * d)) % mod 的非负结果
int f2(long long a, long long b, long long c, long long d, int mod) {
    int o1 = static_cast<int>(a % mod);  // a
    int o2 = static_cast<int>(b % mod);  // b
    int o3 = static_cast<int>(c % mod);  // c
    int o4 = static_cast<int>(d % mod);  // d
    int o5 = (o1 + o2) % mod;  // a + b
    int o6 = (o3 - o4 + mod) % mod;  // c - d
    int o7 = static_cast<int>(static_cast<long long>(o1) * o3 % mod);  // a * c
    int o8 = static_cast<int>(static_cast<long long>(o2) * o4 % mod);  // b * d
    int o9 = static_cast<int>(static_cast<long long>(o5) * o6 % mod);  // (a + b) * (c - d)
    int o10 = (o7 - o8 + mod) % mod;  // (a * c - b * d)
    int ans = (o9 + o10) % mod;  // ((a + b) * (c - d) + (a * c - b * d)) % mod
    return ans;
}

// 替代方案：如果编译器不支持__int128，可以使用此函数
int f1_alternative(long long a, long long b, long long c, long long d, int mod) {
    // 使用模运算分步计算，避免溢出
    a %= mod;
    b %= mod;
    c %= mod;
    d %= mod;
    
    long long ab = (a + b) % mod;
    long long cd = (c - d + mod) % mod;
    long long ac = (a * c) % mod;
    long long bd = (b * d) % mod;
    
    long long abcd = (ab * cd) % mod;
    long long acbd = (ac - bd + mod) % mod;
    
    int result = (abcd + acbd) % mod;
    return result;
}

int main() {
    // 测试用例
    long long a = 1000000000;
    long long b = 2000000000;
    long long c = 3000000000;
    long long d = 4000000000;
    int mod = 1000000007;
    
    // 由于部分编译器不支持__int128，这里使用替代方案
    std::cout << "结果: " << f1_alternative(a, b, c, d, mod) << std::endl;
    std::cout << "结果: " << f2(a, b, c, d, mod) << std::endl;
    
    return 0;
}
