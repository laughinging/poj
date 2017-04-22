#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int i;
    float a,s=0;
    for (i=0; i<12; i++){
        scanf("%f", &a);
        s += a;
    }
    printf("$%.2f\n", s/12);
    return 0;
}
