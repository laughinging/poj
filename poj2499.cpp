#include<iostream>
#include<cstdio>
#include<cstring> // memset
#include<algorithm> // sort
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Scenario #" << i << ":" << endl;
        int a, b;
        cin >> a >> b;
        int l = 0, r = 0;
        while (a != 1 || b != 1) {
            if (a > b) {
                int t = (a - 1) / b;
                l += t;
                a -= t * b;
            } else {
                int t = (b - 1) / a;
                r += t;
                b -= t * a;
            }
        }
        cout << l << " " << r << endl << endl;
    }
    return 0;
}
