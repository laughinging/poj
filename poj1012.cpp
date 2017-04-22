#include<iostream>
#include<cstdio>
using namespace std;

int ans[15];

int joseph(int k) {
    if (ans[k]) 
        return ans[k];
    int i = k + 1;
    while (true) {
        int cur = 0;
        bool flag = true;
        for (int j = 0; j < k; j++) {
            cur = (cur + i) % (k + k - j) - 1;
            if (cur < 0)
                cur += (k + k - j);
            if (cur < k) {
                flag = false;
                break;
            }
        } 
        if (flag) {
            ans[k] = i;
            return i;
        }
        i ++ ;
    }
}

int main(){
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("%d\n", joseph(n));
    }
    return 0;
}
