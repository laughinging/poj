#include<iostream>
#include<cstdio>
#include<cstring> // memset
#include<algorithm> // sort
using namespace std;

char s[1000020];
char t[1000020];
int p[1000020];
int len, Len;

int kmp() {
    int ans = 0;
    int u = 0;
    p[1] = 0;
    for (int i = 2; i <= len; i++) {
        while (u > 0 && s[u+1] != s[i])
            u = p[u];
        if (s[u+1] == s[i]) {
            u ++;
        }
        p[i] = u;
    }
    u = 0;
    for (int i = 1; i <= Len; i++) {
        while (u > 0 && s[u+1] != t[i]) 
            u = p[u];
        if (s[u+1] == t[i])
            u++;
        if (u==len) {
            ans ++;
            u = p[u];
        }

    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    while (n--) {
        scanf("%s", s+1);
        scanf("%s", t+1);
        len = strlen(s+1);
        Len = strlen(t+1);
        cout << kmp() << endl;
    }
    return 0;
}
