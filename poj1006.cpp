#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int p, e, i, d, n=0;
    while (true) {
        scanf("%d %d %d %d", &p, &e, &i, &d);
        n ++;
        if (p == -1) {
            break;
        }
        int s;
        s = (5544*p + 14421*e + 1288*i - d + 21252) % 21252;
        if (s==0) {
            s = 21252;
        }

        printf("Case %d: the next triple peak occurs in %d days.\n", n, s);
    }

    return 0;
}
