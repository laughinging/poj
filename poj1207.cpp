#include<iostream>
#include<cstdio>
using namespace std;

int cycle[1000010];

int main(){
    cycle[1] = 1;
    for (int i = 2; i < 1000005; i++) {
        long long u = i;
        int n = 0;
        while (u > 1000000 || cycle[u] == 0) {
            if (u & 1) {
                u = 3 * u + 1;
            } else {
                u /= 2;
            }
            n ++;
        }
        cycle[i] = n + cycle[u];
    }

    int a, b;
    while (cin >> a >> b) {
        int mx = 0;
        cout << a << " " << b << " ";
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }

        for (int i = a; i <= b; i ++) {
            if (cycle[i] > mx) mx = cycle[i];
        }
        cout << mx << endl;
    }
    return 0;
}
