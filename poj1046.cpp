#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

struct color{
    int R, G, B;
} target[16];

int dst(color a, color b) {
    return pow(a.R - b.R, 2) + pow(a.G - b.G, 2) + pow(a.B - b.B, 2);
}

int main(){
    for (int i = 0; i < 16; i ++) {
        cin >> target[i].R >> target[i].G >> target[i].B;
    }

    color t;

    while (cin >> t.R >> t.G >> t.B) {
        if (t.R == -1 && t.G == -1 && t.B == -1) break;
        int j;
        int minDist = 300000;
        for (int i = 0; i < 16; i ++) {
            int d = dst(target[i], t);
            if (d < minDist) {
                minDist = d;
                j = i; 
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", t.R, t.G, t.B, target[j].R, target[j].G, target[j].B);
    }

    return 0;
}
