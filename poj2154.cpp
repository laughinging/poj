#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool isprime[40010];
int prime[10000];

int power(int a, int b, int m) {
    int s = 1;
    a = a % m;
    while (b) {
        if (b & 1) {
            s = (s * a) % m;
        }
        b = b >> 1;
        a = (a * a) % m;
    }
    return s;
}

int phi(int x) {
    int s = x;
    for (int i = 0; i < 10000 && prime[i] * prime[i] <= x; i++) {
        if (x % prime[i] == 0) {
            s = s / prime[i] * (prime[i] - 1);
        }
        while (x % prime[i] == 0) {
            x /= prime[i];
        }
    }
    if (x > 1) {
        s = s / x * (x - 1);
    }
    return s;
}

int main(){
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    int k = 0;
    for (int i = 2; i < 40010; i++) {
        if (isprime[i]) {
            prime[k++] = i;
            for (int j = i+i; j < 40010; j += i) {
                isprime[j] = false;
            }
        }
    }

    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        int x, p;
        scanf("%d %d", &x, &p);
        int ans = 0;
        for (int j = 1; j * j < x; j++) {
            if (x % j == 0) {
                ans = (ans + phi(j) % p * power(x, x / j - 1, p) + phi(x / j) % p * power(x, j - 1, p)) % p;
            }
        }
        int t = (int) sqrt((double) x);
        if (t * t == x) {
            ans = (ans + phi(t) % p * power(x, t - 1, p)) % p; 
        }
        
        printf("%d\n", ans);
    }
    return 0;
}
