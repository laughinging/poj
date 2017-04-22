#include<iostream>
#include<cstdio>
using namespace std;

int gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// find x, y st. ax + by = gcd(a, b)
int ext_euclid(long long a, long long b, long long *x, long long *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    long long x1, y1;
    long long g = ext_euclid(b,  a % b, &x1, &y1);

    *x = y1; 
    *y = x1 - (a / b) * y1;
    return g;
}


int main(){
    long long x, y, m, n, l;
    scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l);
    long long a = n - m;
    long long b = l;
    long long d = x - y;
    long long t = gcd(a, b);
    if (d % t != 0) {
        printf("Impossible");
        return 0;
    }
    a /= t;
    b /= t;
    long long u, v, g;
    g = ext_euclid(a, b, &u, &v);
    u *= d / t;
    b /= t;
    printf("%lld\n", (x % b + b) % b);
    return 0;
}
