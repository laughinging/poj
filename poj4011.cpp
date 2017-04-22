#include<iostream>
#include<cstdio>
#include<cstring> // memset
#include<algorithm> // sort
using namespace std;

int main(){
    int a;
    cin >> a;
    cout << max(0, 199 - a) << endl;
    return 0;
}
