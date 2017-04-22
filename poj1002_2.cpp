#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;

int main(){
    int cases;
    scanf("%d", &cases);

    map<int, int> tb;
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
        tb[t] ++;
    }
    
    bool dup = false;
    for (map<int, int>::iterator p=tb.begin(); p!=tb.end(); ++p) {
        if (p->second > 1) {
            printf("%03d-%04d %d\n", p->first / 10000, p->first % 10000, p->second);
            dup = true;
        }
    }
    if (!dup) {
        printf("No duplicates.\n");
    }
    return 0;
}
