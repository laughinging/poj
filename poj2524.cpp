#include<iostream>
#include<cstdio>
#include<cstring> // memset
#include<algorithm> // sort
using namespace std;
int pre[50010];
int n;

void init(int x) {
    for (int i = 1; i <= x; i++) pre[i] = i;
}

int find(int x) {
    int t = x;
    while (pre[t] != t) t = pre[t];
    int k = x;
    while (k != t) {
        int j = pre[k];
        pre[k] = t;
        k = j;
    }
    return t;
}

void join(int x, int y) {
    int t = find(x);
    int u = find(y);
    if (t != u) {
        pre[u] = t;
        n --;
    }
}

int main(){
    int l;
    int c = 0;
    while (scanf("%d %d", &n, &l)) {
        if (n == 0 && l == 0) break;
        c ++;
        init(n);
        for (int i = 1; i <= l; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            join(x, y);
        }
        cout << "Case " << c << ": " << n << endl;
    }
    return 0;
}
