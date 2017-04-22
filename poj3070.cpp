#include<iostream>
#include<cstdio>
#include<cstring> // memset
#include<algorithm> // sort
using namespace std;

int f[15020];

int main() {
    f[1] = 1;
    for (int i = 2; i < 15000; i++) {
        f[i] = (f[i-1] + f[i-2]) % 10000;
    }
    int x;
    while (cin >> x && x != -1) {
        cout << f[x % 15000] << endl;
    }
    return 0;
}
