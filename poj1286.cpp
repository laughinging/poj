#include<iostream>
#include<cstdio>
using namespace std;

long long p[24];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    p[0] = 1;
    for (int i = 1; i < 24; i++) {
        p[i] = p[i-1] * 3;
    }

    int n;
    while (true) {
        scanf("%d", &n);
        if (n == -1) break;
        if (n == 0) {
            printf("0\n");
            continue;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += p[gcd(n, i)];
        }

        ans += n * p[(n+1) / 2];
        if (n % 2 == 0) ans += n * p[n / 2];

        ans /= 2 * n;
        printf("%lld\n", ans);
    }
    return 0;
}
