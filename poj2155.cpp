#include <iostream>
#include <cstdio>
#include <cstring> // memset
#include <algorithm> // sort
using namespace std;

int A[50020][50020];

int main() {
    int cases;
    scanf("%d", &cases);
    for (int kk = 0; kk < cases; kk++) {
        int N, T;
        scanf("%d %d", &N, &T);
        for (int i = 0; i < T; i++) {
            char inst;
            scanf("%s", inst);
            if (inst[0] == 'Q') {
                int i,j;
                scanf("%d %d", &i, &j);
                req(i,j);
            } else {
                int x1, x2, y1, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                cg(x1, y1, x2, y2);
            }
        }
    }
    
    
    return 0;
}
