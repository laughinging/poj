#include<iostream>
#include<cstdio>
using namespace std;
const float PI = 3.14159265358979f;

int main(){
    int cases;
    scanf("%d", &cases);

    for (int i=1; i<=cases; i++) {
        float x, y;
        int n;
        scanf("%f %f", &x, &y);
        n = (int)(x*x + y*y)*PI / 100 + 1;

        printf("Property %d: This property will begin eroding in year %d.\n", i, n);
    }
    printf("END OF OUTPUT.\n");

    return 0;
}
