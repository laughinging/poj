#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int len, n; 
bool vis[70];
bool flag;
int stick[70];

int cmp(int a, int b) {
    return a > b;
}
void dfs(int num_stick, int cur_stick, int cur_len) {
    if (flag) return;
    
    if (cur_len == len) {
        if (num_stick == n)
            flag = true;
        else 
            dfs(num_stick, 0, 0);
        return;
    }
    if (cur_len == 0) {
        int k = 0;
        while (vis[k]) k++;
        vis[k] = true;
        dfs(num_stick + 1, k + 1, stick[k]);
        vis[k] = false;
        return;
    }
    for (int i = cur_stick; i < n; i++) {
        if (!vis[i - 1] && stick[i - 1] == stick[i])
            continue;
        if (!vis[i] && cur_len + stick[i] <= len) {
            vis[i] = true;
            dfs(num_stick + 1, i + 1, cur_len + stick[i]);
            vis[i] = false;
        }
    }
}


int main(){
    while (true) {
        scanf("%d", &n);
        if (n == 0)
            break;
        int s = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &stick[i]);
            s += stick[i];
        }
        sort(stick, stick + n, cmp);
        
        flag = false;
        for (len = stick[0]; len <= s/2; len ++) {
            if (s % len == 0){
                memset(vis, 0, sizeof(vis));
                dfs(0, 0, 0);
                if (flag)
                    break;
            }
        }
        if (!flag)
            printf("%d\n", s);
        else
            printf("%d\n", len);
    }
    return 0;
}
