#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int n;
int a[210];

void encode(int *a, int *b, int *c) {
    int u[210];
    for (int i = 1; i <= n; i++) 
        u[b[i]] = a[i]; 
    memcpy(c, u, sizeof(int) * (n+1));
}

void mul(int *a, int *b, int *c) {
    int u[210];
    for (int i = 1; i <= n; i++)
        u[i] = b[a[i]];
    memcpy(c, u, sizeof(int) * (n+1));
}

void print_array(int *a) {
    for (int i = 1; i <= n; i++) 
        printf("%d ", a[i]);
    printf("\n");
}

int main(){
    while (true) {
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++) 
            scanf("%d", &a[i]);
        while (true) {
            int u[210];
            memcpy(u, a, sizeof(int) * (n+1));

            int b;
            char c[210];
            scanf("%d", &b);
            getchar();
            if (b==0)
                break;

            int s[210];
            for (int i = 1; i <= n; i++) 
                s[i] = i;

            while (b) {
                if (b & 1) {
                    encode(s, u, s);
                }
                b >>= 1;
                mul(u, u, u);
            }
            
            gets(c);
            char ans[210];
            for (int i = 1; i <= n; i++) {
                if (s[i] <= strlen(c))
                    ans[i] = c[s[i] - 1];
                else 
                    ans[i] = ' ';
            }

            for (int i = 1; i <= n; i++)
                printf("%c", ans[i]);
            printf("\n");
        }
        puts("");
    }
    return 0;
}
