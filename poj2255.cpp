#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[30], b[30];

void f(int i, int j, int k, int v) {
    int t = strchr(b, a[i]) - b;
    if (k < t) {
        f(i + 1, i + t - k, k, t - 1);
    }
    if (t < v) {
        f(i + 1 + t - k, j,  t + 1, v);
    }
    cout << a[i];
}

int main(){
    while (scanf("%s %s", a, b)!=EOF) {
        f(0, strlen(a) - 1, 0, strlen(b) - 1);
        cout << endl;
    }
    return 0;
}
