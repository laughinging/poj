#include<iostream>
#include<cstdio>
using namespace std;
int n, s;
int a[1010], b[1010], c[1010];

void print_array(int *a) {
    for (int i = 1; i <= n; i++) 
        printf("%d ", a[i]);
    printf("\n");
}

void shuffle(int *a, int *b, int *c) {
    int d[1010];
    memcpy(d, a, sizeof(int) * (n+1));
    for (int i = 1; i <= n; i++) {
        d[b[i]] = a[i];
    }
    memcpy(c, d, sizeof(int) * (n+1));
}



int main(){
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++) 
        a[i] = i;
    for (int i = 1; i <= n; i++) 
        scanf("%d", &b[i]);
    memcpy(c, a, sizeof(a));

    for (int i = 1; i < 5; i++) {
    shuffle(a, b, a);
    print_array(a);}

    printf("=====\n");
    int e[10] = {0, 3, 5, 2, 4, 6, 1, 7};
    for (int i =1; i<5; i++) {
        shuffle(a, e, a);
        print_array(a);
    }
    while (s) {
        if (s & 1) {
            shuffle(c, b, c);
        }
        shuffle(a, b, b);
        s >>= 1;
    }
    print_array(c);

    return 0;
}
