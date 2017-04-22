#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int x[26], y[26];

void f(char a[], int z[26]) {
    int u[26] = {};
    int l = strlen(a);
    for (int i = 0; i < l; i++)
        u[a[i] - 'A'] += 1;
    memcpy(z, u, sizeof(u));
}

bool compare(int *a, int *b) {
    for (int i = 0; i < 26; i++) 
        if (a[i] != b[i])
            return false;
    return true;
}

int main(){
    char a[110], b[110];
    scanf("%s", a);
    f(a, x);
    scanf("%s", b);
    f(b, y);
    sort(x, x + 26);
    sort(y, y + 26);
    if (compare(x,y))
        printf("YES\n");
    else 
        printf("NO\n");
    return 0;
}
