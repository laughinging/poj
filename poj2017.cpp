#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n;
    while (cin >> n) {
        if (n == -1) break;
        int c = 0, s = 0;
        while (n--) {
            int a, b;
            cin >> a >> b;
            s += a * (b - c);
            c = b;
        }
        cout << s << " miles" << endl;
    }

    return 0;
}
