#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    char a;
    while (true) {
        a = getchar();
        if (a == '#') break;
        
        int ans = a - 'A' + 1;
        int i = 2;

        while (true) {
            a = getchar();
            if (a == '\n') break;
            if (a == ' ') {
                i ++;
                continue;
            }
            ans += i * (a - 'A' + 1);
            i ++;
        }
        cout << ans << endl;
    }

    return 0;
}
