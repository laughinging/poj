#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    float a, s;
    int i;
    scanf("%f", &a);
    while (a > 0) {
        s = 0;
        i = 0;
        while (s < a) {
            i ++;
            s += 1.0 / (1+i);
        }
        printf("%d card(s)\n", i);
        scanf("%f", &a);
    }
    return 0;
}
