#include<iostream>
#include<cstdio>

using namespace std;
const int M = 1 << 30;

int pow(int a, int b) {
    int s = 1;
    while (b) {
        if (b & 1) 
            s *= a;
        a *= a;
        b >>= 1;
    }
    return s;
}

void factor(long long x) {
    int k = 0;
    int u = x;
    int p[10000] = {};
    int c[10000] = {};
    for (int i = 2; i * i <= u; i++) {
        if (x % i == 0) {
            p[k] = i;
            while (x % i == 0) {
                c[k] ++;
                x /= i;
            }
            k ++;
        }
    }
    if (x > 1) {
        p[k] = x;
        c[k] ++;
        k ++;
    }

    for (int i = k-1; i >=0; i--) {
        printf("%d %d", p[i], c[i]);
        if (i != 0)
            printf(" ");
    }
    printf("\n");
}

int main(){
    int p, e;
    while (true) {
        long long t = 1;
        scanf("%d", &p);
        if (p==0)
            break;
        scanf("%d", &e);
        t *= pow(p, e);
        while (getchar() != '\n') {
            scanf("%d", &p);
            scanf("%d", &e);
            t *= pow(p, e);
        }
        factor(t-1);
    }

    return 0;
}
