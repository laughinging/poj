#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n;
    char a[35];
    cin >> n;
    getchar();
    while (n--) {
        cin >> a;
        int s = 0;
        for (int i = 0; i < 32; i++) {
            if (i % 8 == 0) s = 0;
            s = a[i] - '0' + s * 2;
            if (i % 8 == 7) {
                cout << s;
                i == 31 ? cout << endl : cout << '.';
            }
        }
    }
    return 0;
}
