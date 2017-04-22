#include<iostream>
#include<cstdio>
using namespace std;
int prime[15000];
bool isPrime[50000];
bool p[1000010];

int get_prime() {
    int cnt = 0;
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for (int i = 2; i < 50000; i++) 
        if (isPrime[i]) {
            prime[cnt++] = i; 
            for (int j = i + i; j < 50000; j += i) 
                isPrime[j] = false;
        }
    return cnt;
}


int main(){
    int cnt = get_prime();
    int l, r;
    while (scanf("%d%d", &l, &r) != EOF) {
        memset(p, true, sizeof(p));
        if (l == 1)
            l = 2;
        for (int i = 0; i < cnt; i++) {
            if (prime[i] > r / prime[i]) 
                break;
            long long u = (long long) ((l - 1) / prime[i] + 1) * prime[i];
            if (u == prime[i]) 
                u += u;
            for (long long j = u - l; j <= r - l; j += prime[i]) {
                p[j] = false;
            }
        }

//        for (int i = 0; i <= r - l; i++)
//            if (p[i]) printf("%d\n", i+l);

        int c[1000010];
        int n = 0;
        for (int i = 0; i <= r - l; i++) {
            if (p[i]) {
                c[n++] = i;
            }
        }
        if (n < 2) {
            printf("There are no adjacent primes.\n");
        } else {
            int max_dist = 0;
            int a1, a2, b1, b2;
            int min_dist = r - l + 1;
            for (int i = 1; i < n; i++) {
                int u = c[i] - c[i - 1];
                if (u > max_dist) {
                    max_dist = u;
                    a1 = c[i - 1];
                    a2 = c[i];
                }
                if (u < min_dist) {
                    min_dist = u;
                    b1 = c[i - 1];
                    b2 = c[i];
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n", b1+l, b2+l, a1+l, a2+l);
        }
    }
    return 0;
}
