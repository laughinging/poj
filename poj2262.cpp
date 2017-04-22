#include<iostream>
#include<cstdio>
using namespace std;

bool prime[1000010];
int num;
int prime_list[100000];

int main(){
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int i = 2; i < 1000010; i ++) {
        if (prime[i]) {
            prime_list[num] = i;
            num ++;
            for (int j = i + i; j < 1000010; j += i)
                prime[j] = false;
        }
    }

    int n;
    while (cin >> n) {
        if ( n == 0)
            break;
        for (int i = 0; i < num; i ++) {
            if (prime[n - prime_list[i]]){
                printf("%d = %d + %d\n", n, prime_list[i], n - prime_list[i]);
                break;
            }
        }
    }
    return 0;
}
