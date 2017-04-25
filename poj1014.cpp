#include <iostream>
#include <cstdio>
#include <cstring> 
#include <algorithm> 
using namespace std;

int a[10];
int b[10];
int total;

bool dfs(int v, int mx) {
    if (v == total)
        return true;
    
    for (int i = mx; i > 0; i--){
        if (a[i]) {
            if (v + i <= total) {
                a[i] --;
                return dfs(v + i, i);
            }
        }
    }
    return false;
}

int main() {
    for (int i = 1; i <= 6; i++) 
        b[i] = i;
    int tt = 1;
    while (1) {
        total = 0;
        for (int i = 1; i <= 6; i++) {
            cin >> a[i];
            total += a[i] * i;
        }
        if (total == 0) break;
        cout << "Collection #" << tt++ << ":\n";
        if (total%2) {
            cout << "Can't be divided.\n" << endl;
            continue;
        }
        total /= 2;
        cout << (dfs(0,6) ? "Can be divided.\n" : "Can't be divided.\n") << endl;
    }

    
    
    return 0;
}
