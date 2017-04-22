#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int a[5] = {0, 3, 6, 8, 10};
    int s, d;

    while (cin >> s >> d) {
        int i = 1;
        while (s * i <= (5 - i) * d) i++;

        int ans = a[i - 1] * s - (12 - a[i - 1]) * d; 
        if (ans >= 0)
            cout << ans << endl;
        else cout << "Deficit" << endl;
    }

    return 0;
}
