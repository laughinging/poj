#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
    int cases;
    scanf("%d", &cases);

    int n = 0;
    int data[100000];
    for (int i = 0; i < cases; i++){
        char s[100];
        scanf("%s", s);
        int t = 0;
        for (int j = 0; j < strlen(s); j++){
            if (isdigit(s[j])) {
                t = t * 10 + s[j] - '0';
            } else {
                if (isalpha(s[j])) {
                    t = t * 10 + (s[j] - 'A' - (s[j] > 'Q')) / 3 + 2;
                } 
            }
        }
        data[n++] = t;
    }
    
    bool dup = false;
    sort(data, data+n);
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", data[i]);
    // }
    int i = 0, num = 1;
    while (i < n) {
        while (data[i] == data[i+1]) {
            num ++;
            i ++;
        }
        if (num > 1) {
            printf("%03d-%04d %d\n", data[i] / 10000, data[i] % 10000, num);
            num = 1;
            dup = true;
        }
        i ++;
    }
    if (!dup) {
        printf("No duplicates.\n");
    }
    return 0;
}
