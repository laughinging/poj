#include<iostream>
#include<cstdio>
#include<cstring> // memset
#include<algorithm> // sort
#include<vector>
using namespace std;

char s[1000020];
int p[1000020];
int len;
vector <int> gqy;

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
    u = len;
    gqy.clear();
    while (u) {
        gqy.push_back(u);
        u = p[u];
    }
    for (int i = gqy.size()-1; i >=0; i--) {
        cout << gqy[i];
        if (i != 0)
            cout << ' ';
    }
    cout << endl;
}

int main(){
    while (scanf("%s", s+1) + 1) {
        len = strlen(s+1);
        kmp();
    }
    return 0;
}
