#include<iostream>
#include<cstdio>
using namespace std;

bool prime[1000010];

int main(){
    memset(prime, true, sizeof(prime));

    prime[1] = false;
    for (int i = 2; i < 1000010; i ++) {
        if (prime[i]) {
            for (int j = i + i; j < 1000010; j += i)
                prime[j] = false;
        }
    }

    int a, d, n;
    while (scanf("%d %d %d", &a, &d, &n)) {
        if (a == 0 && d == 0 && n == 0) break;
        while (n > 0) {
            while (!prime[a])
                a += d;
            n --;
            if (n > 0) a += d;
        }
        printf("%d\n", a);
    }
    return 0;
}
