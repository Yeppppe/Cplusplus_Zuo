//* 求最大公约数合最小公倍数


int gcd(int a,int b){
    return b == 0 ? a : gcd(b, a % b);
}


int lcm(int a,int b){
    return a/gcd(a,b)*b;
}