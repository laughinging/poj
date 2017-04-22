#include<iostream>
#include<cstdio>
using namespace std;

bool prime[10010];
int prime_list[2000];
int n;
int cnt[10010]; 

int main(){
    memset(prime, true, sizeof(prime));
    for (int i = 2; i < 10010; i++) {
        if (prime[i]) {
            prime_list[n] = i;
            n ++;
            for (int j = i + i; j < 10010; j += i) 
                prime[j] = false;
        }
    }

    for (int i = 0; i < n; i ++) {
        int s = 0;
        for (int j = i; j < n; j ++) {
            s += prime_list[j];
            if (s > 10000)  break;
            cnt[s] ++;
        }
    }

    int x;
    while (cin >> x) {
        if (x == 0)
            break;
        cout << cnt[x] << endl;
    }
    return 0;
}
