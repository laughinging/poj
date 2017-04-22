#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s[110];
char a[110];

int main(){
    while (cin >> a){
        if (strcmp(a, "0") == 0) break;
        int l = strlen(a);
        for (int i = 0; i < l; i ++) {
            s[i] += a[l - i - 1] - '0';
        }
    }

    /*
    for (int i = 0; i < 110; i ++)
        cout << s[i] << ' ';
    cout << endl;
    */

    for (int i = 0; i < 110; i ++) {
        if (s[i] > 9) {
            s[i + 1] += s[i] / 10;
            s[i] %= 10;
        }
    }

    /*
    for (int i = 0; i < 110; i ++)
        cout << s[i] << ' ';
    cout << endl;
    */

    int j = 109;
    while (s[j] == 0) j--;
    for (int i = j; i >= 0; i--)
        cout << s[i];
    cout << endl;
    return 0;
}
