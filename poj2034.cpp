#include<iostream>
#include<cstdio>
using namespace std;
bool isPrime[20000];
bool vis[1020];
int ans[1020];
int m, n, d;

void get_prime() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for (int i = 2; i < 20000; i++) 
        if (isPrime[i])
            for (int j = i + i; j < 20000; j += i)
                isPrime[j] = false;
}

bool ok(int pos, int x) {
    if (pos == 0)
        return true;
    int t = 1;
    int s = x;
    while (t < d && t <= pos) {
        s += ans[pos - t];
        if (isPrime[s])
            return false;
        t ++;
    }
    return true;
}

bool dfs(int pos) {
    if (pos == m - n + 1)
        return true;
    for (int i = n; i <= m; i++) {
        if (!vis[i] && ok(pos, i)) {
            ans[pos] = i;
            vis[i] = true;
            if (dfs(pos + 1))
                return true;
            vis[i] = false;
        }
    }
    return false;
}

int main(){
    get_prime();
    while (true) {
        scanf("%d %d %d", &n, &m, &d);
        if (n==0 && m == 0 && d == 0)
            break;
        memset(vis, false, sizeof(vis));
        memset(ans, 0, sizeof(ans));
        if (dfs(0)) {
            for (int i = 0; i < m - n; i++) 
                printf("%d,", ans[i]);
            printf("%d\n", ans[m - n]);
        } else {
            printf("No anti-prime sequence exists.\n");
        }
    }
    return 0;
}
