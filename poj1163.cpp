#include <iostream>
#include <cstdio>
#include <cstring> // memset
#include <algorithm> // sort
using namespace std;
int s[120];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j --) {
            s[j] = max(s[j], s[j-1]);
        }
        for (int j = 1; j <= i; j++) {
            int a;
            cin >> a;
            s[j] += a;
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] > mx) mx = s[i];
    }
    cout << mx << endl;
    return 0;
}
