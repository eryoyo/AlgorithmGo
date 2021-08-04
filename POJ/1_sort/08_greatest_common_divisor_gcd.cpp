//
// Created by eryo on 2021/8/4.
//

//greatest common divisor最大公因数
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

//least common multiple最小公倍数
int lcm(int a, int b){
    return a * b / gcd(a, b);
}

//扩展欧几里得算法extended gcd
//在求得 a 和 b 最大公因数的同时，
//也得到它们的系数 x 和 y，从而使 ax + by = gcd(a, b)
int xGCD(int a, int b, int &x, int &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1, y = x1 - (a / b) * y1;
    return gcd;
}