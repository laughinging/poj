#include<iostream>
#include<cstdio>
using namespace std;
const int MOD = 9973;

void print_mat(long long a[15][15], int m) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%lld ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

long long phi(int x) {
    long long s = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            s = s / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) s = s / x * (x - 1);
    return s;
}

void mul(long long a[15][15], long long b[15][15], int m, long long r[15][15]) {
    long long s[15][15] = {};

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                s[i][j] += a[i][k] * b[k][j];
            }
            s[i][j] %= MOD;
        }
    }
    memcpy(r, s, sizeof(s));
}

void fast_exp(long long a[15][15], int m, int e, long long r[15][15]) {
    long long k[15][15] = {};
    long long s[15][15] = {};
    
    for (int i = 1; i <= m; i++) 
        s[i][i] = 1;

    for (int i = 1; i <= m; i++) 
        for (int j = 1; j <= m; j++) 
            k[i][j] = a[i][j];

    while (e) {
        if (e & 1) 
            mul(s, k, m, s);
        mul(k, k, m, k);
        e >>= 1;
    }
    memcpy(r, s, sizeof(s));
}

long long pow(int a, int b, int p) {
    a %= p;
    int s = 1;
    while (b) {
        if (b & 1) 
            s = s * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return s;
}

long long solutions(long long a[15][15], int m, int k) {
    long long s[15][15] = {};
    long long res = 0;
    fast_exp(a, m, k, s);
    for (int i = 1; i <= m; i++) {
        res = (res + s[i][i]) % MOD;
    }
        
    return res; 
}

long long inverse(int x, int p) {
    return pow(x, p-2, p);
}

int main(){
    int cases;
    scanf("%d", &cases);

    for (int i = 0; i < cases; i++) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        long long c[15][15] = {};
        for (int i = 1; i <= m; i++) 
            for (int j = 1; j <= m; j++)
                c[i][j] = 1;

        for (int j = 0; j < k; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            c[a][b] = 0;
            c[b][a] = 0;
        }
        
        long long t[15][15] = {};

        long long ans = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i * i != n) {
                    ans += solutions(c, m, i) * phi(n / i) + solutions(c, m, n / i) * phi(i);
                } else {
                    ans += solutions(c, m, i) * phi(i);
                }
            }
            ans %= MOD;
        }
        ans *= inverse(n, MOD);
        printf("%lld\n", ans % MOD);
    }
    return 0;
}
