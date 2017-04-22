#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int a[400], s[400];

int main(){
    char r[100];
    int n;
    while (scanf("%s %d", r, &n) != EOF) {
        memset(a, 0, sizeof(a));
        memset(s, 0, sizeof(s));

        int j = 0, p = 0;

        int i = strlen(r) - 1;
        while (r[i] == '0') {
            r[i--] = '\0';
        }
        if (r[i] == '.') {
            r[i] = '\0';
        } 
        
        int l = strlen(r);
        for (int i = l-1; i >= 0; i--) {
            if (isdigit(r[i])) {
                a[j++] = r[i] - '0';
            } 
            if (r[i] == '.') {
                p = l - i - 1;
            }
        }

        p *= n;
        memcpy(s, a, sizeof(a));

        for (int i = 1; i < n; i++) {
            int b[400];
            memset(b, 0, sizeof(b));

            for (int j = 0; j < 10; j++) {
                int c = 0;
                for (int k = 0; k < 200; k++) {
                    int t = b[k+j] +  a[j] * s[k] + c;
                    b[k+j] = t % 10;
                    c = t / 10;
                }
            }
            
            memcpy(s, b, sizeof(s));
        }

        i = 200;
        while (s[i] == 0) i--;
        if (i < 0) {
            printf("0\n");
            continue;
        }

        for (int j = p; j > i; j--) {
            if (j == p) {
                printf(".");
                continue;
            }
            printf("0");
        }
 
        for (int j = i; j >= 0; j--) {
            printf("%d", s[j]);
            if (j == p && p != 0) {
                printf(".");
            }
        }

        printf("\n");
    }

    return 0;
}
