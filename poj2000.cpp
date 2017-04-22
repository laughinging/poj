#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

int g(int n) {
    int l = 0, r = n;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (m * (m + 1) / 2 > n) {
            r = m;
        } else {
            l = m;
        }
    }
    return l;
}

int f(int n) {
    //int a = int(sqrt(n * 2)); 
    //if (a * (a + 1) / 2 > n) a--;
    int a = g(n);
    int s = a * (a + 1) * (2 * a + 1) / 6;
    s += (a + 1) * (n - a * (a + 1) / 2);
    return s;
}

int main(){
    int n;
    while (cin >> n) {
        if (n == 0) break;
        f(n);
        cout << n << ' ' << f(n) << endl;
    }

    return 0;
}
