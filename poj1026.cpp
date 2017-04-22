#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int a[210]; // origin replace
int b[210]; // circles
bool flag[210];

struct circle {
    int len;
    int start;  
} circles[210];

int main(){
    while (true) {
        int n;
        memset(flag, false, sizeof(flag));
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        int cnt = 0;
        int u = 0;
        for (int i = 1; i <= n; i++) {
            if (flag[i])
                continue;
            circles[cnt].start = u;
            int t = i;
            while (true) {
                b[u++] = t;
                flag[t] = true;
                t = a[t];
                if (t == i) 
                    break;
            }
            circles[cnt].len = u - circles[cnt].start;
            cnt ++;
        }

        int r;
        while (true) {
            scanf("%d", &r);
            getchar();
            if (r == 0)
                break;
            int c[210];
            int k = 0;
            for (int i = 0; i < cnt; i++) {
                int v = r % circles[i].len;
                for (int j = 0; j < circles[i].len; j++) 
                    c[k++] = b[(j + v) % circles[i].len + circles[i].start];
            }

            char s[210];
            gets(s);
            int l = strlen(s);
            char e[210] = {};
            for (int i = 0; i < n; i++) 
                if (b[i]  > l) {
                    e[c[i]] = ' ';
                } else {
                    e[c[i]] = s[b[i]-1];
                }
            for (int i = 1; i <= n; i++) 
                printf("%c", e[i]);
            printf("\n");
        }
        puts("");
    }
    return 0;
}
