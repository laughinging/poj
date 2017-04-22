#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int a[10010]; // origin
int b[10010]; // destination
int c[10010]; // sub-circles counts
int d[10010]; // sub-circles' minimal element
bool flag[10010];
int n;
int k; // index of the sub-circles

void dfs(int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x && !flag[i]) {
            flag[i] = true;
            c[k] += 1;
            d[k] = min(d[k], a[i]); 
            dfs(b[i]);
        }
    }
}

int main(){
    scanf("%d", &n);

    int m = 1 << 30;
    long long s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        m = min(m, a[i]);
        s += a[i];
    }
    sort(b, b + n);
    k = 0;
    
    for (int i = 0; i < n; i++) {
        if (flag[i])
            continue;
        c[k] = 1;
        d[k] = a[i];
        flag[i] = true;
        dfs(b[i]);
        k ++;
    }

    for (int i = 0; i < k; i++) {
        s += min(d[i] * (c[i] - 2), m * (c[i] + 1) + d[i]);
    }
    printf("%lld\n", s);
    return 0;
}
