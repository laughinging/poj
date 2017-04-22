#include<iostream>
#include<cstdio>
using namespace std;

bool check(int n) {
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 10; j ++) {
            for (int k = 0; k < 10; k ++) {
                for (int t = 0; t < 10; t++) {
                    if (i * 1001 + j * 101 + k * 11 + t * 2 == n) return true;
                }
            }
        }
    }
    return false;
}
int main(){
    for (int i = 1; i < 10000; i++) {
        if (!check(i))
            cout << i << endl; 
    }
    return 0;
}
