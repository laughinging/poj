#include <iostream>
#include <cstdio>
#include <cstring> // memset
#include <algorithm> // sort
using namespace std;

int s[4] = {0, 5, 3, 1}; // number of 2*2 after i 3*3 

int main() {
    int a, b, c, d, e, f;
    while (cin >> a >> b >> c >> d >> e >> f) {
        if (a + b + c + d + e + f == 0) break;
        int ans = 0;
        ans += d + e + f;
        if (c > 0)
            ans += (c-1)/4 + 1;
        int k = 5 * d + s[c%4];
        if (k < b)
            ans += (b-k-1) / 9 + 1;
        k = 36*ans - 36*f - 25*e - 16*d - 9*c - 4*b;
        if (k < a)
            ans += (a - k - 1) / 36 + 1;
        cout << ans << endl;
   }
    return 0;
}
