#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[110];

int main(){
    int x;
    while (cin >> x) {
        memset(a, 0, sizeof(a));
        if (x == -1) break;
        a[x] += 1;

        while (cin >> x) {
            if (x == 0) break;
            a[x] += 1;
        }

        int cnt = 0;
        for (int i = 1; i < 51; i++) 
            if (a[i] != 0 && a[i*2] != 0)
                cnt += 1;
        cout << cnt << endl;
    }

    return 0;
}
