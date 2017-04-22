#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[110][110];
int s[110];

int dp(int *a) {
    int m = a[0];
    int d = 0;
    int r = a[0];
    for (int i = 0; i < n; i++) {
        d = max(0, d) + a[i];
        r = max(d, r);
    }
    return r;
}

void print(int *a) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int ans = a[0][0];
    for (int i = 0; i < n; i++) {
        memset(s, 0, sizeof(s));
        for (int j = i; j < n; j++) {
            for (int v = 0; v < n; v ++) 
                s[v] += a[j][v];
            ans = max(ans, dp(s));
        }
    }
    printf("%d\n", ans);
    return 0;
}
