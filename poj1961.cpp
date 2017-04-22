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
    int c = 0; 
    while (scanf("%d", &len)) {
        if (len == 0) break;
        cout << "Test case #" << ++c << endl;
        scanf("%s", s+1);
        kmp();
        int u = p[len];
        for (int i = 1; i <= len; i++) {
            if (p[i] > 0 && i % (i - p[i]) == 0)
                cout << i << ' ' << i / (i - p[i]) << endl;
        }
        cout << endl;
    }
    return 0;
}
