#include<iostream>
#include<cstdio>
#include<cstring> // memset
#include<algorithm> // sort
using namespace std;

char s[1000020];
int p[1000020];
int len;

void kmp() {
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
}

int main(){
    while (true) {
        scanf("%s", s+1);
        if (s[1] == '.') break;
        len = strlen(s+1);
        kmp();
        int u = p[len];

        while (len % (len - u) != 0) {
            u = p[u];
        }
        cout << len / (len - u) << endl;
    }
    return 0;
}
