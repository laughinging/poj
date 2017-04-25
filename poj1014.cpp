#include <iostream>
#include <cstdio>
#include <cstring> 
#include <algorithm> 

using namespace std;

int a[10];
int b[10];
int total;

bool dfs(int v, int mx) {
    if (v == 0)
        return true;
    if (b[mx] < v) 
        return false;
    
    for (int i = min(v / mx, a[mx]); i >= 0; i--){
        //cout << "mx: " << mx << "number: " << i << "value: " << v << endl;
        if (i*mx + b[mx-1] < v)
            break;
        if (dfs(v - i*mx, mx-1)){
            return true;
        }
    }
    return false;
}

int main() {
    int tt = 1;
    while (1) {
        total = 0;
        //memset(b, 0, sizeof(b));
        for (int i=0; i < 10; i++)
            b[i] = 0;
        for (int i = 1; i <= 6; i++) {
            cin >> a[i];
            total += a[i] * i;
            b[i] += total;
        }
        if (total == 0) break;
        cout << "Collection #" << tt++ << ":\n";
        if (total%2) {
            cout << "Can't be divided.\n" << endl;
            continue;
        }
        total /= 2;
        //cout << total << endl;
        cout << (dfs(total, 6) ? "Can be divided.\n" : "Can't be divided.\n") << endl;
    }
    return 0;
}
