#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int m[16] = {
    0xf888, 0xf444, 0xf222, 0xf111, 
    0x8f88, 0x4f44, 0x2f22, 0x1f11, 
    0x88f8, 0x44f4, 0x22f2, 0x11f1, 
    0x888f, 0x444f, 0x222f, 0x111f
};

int main(){
    int s = 0;
    char a;
    while (true){
        a = getchar();
        if (a == '+')
            s = (s << 1) + 1;
        if (a == '-')
            s = s << 1;
        if (a == EOF) break;
    }

    int t = 20;
    int move = 0;
    for (int i = 0; i < 65536; i ++) {
        int v = s;
        for (int j = 0; j < 16; j ++) {
            if ((i >> j) & 1) {
                v ^= m[j];
            }
        }

        if (v == 0) {
            if (__builtin_popcount(i) < t) {
                t = __builtin_popcount(i);
                move = i;
            }
        }
    }
    if (t == 20) {
        cout << "Impossible" << endl;
    } else {
        cout << t << endl;
        for (int i = 0; i < 16; i++) {
            if ((move >> i) & 1) 
                cout << i / 4 + 1 << ' ' << i % 4 + 1 << endl;
        }
    }

    return 0;
}

