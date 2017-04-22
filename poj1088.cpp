#include<iostream>
#include<cstdio>
using namespace std;

int a[110][110];
int r[110][110];
int row, col;
void print();

int dp(int x, int y) {
    if (r[x][y] > 0)
        return r[x][y];
    int m = 0;
    if (x > 0 && a[x - 1][y] < a[x][y])
        m = max(m, dp(x - 1, y));
    if (y > 0 && a[x][y - 1] < a[x][y])
        m = max(m, dp(x, y - 1));
    if (x + 1 < row && a[x + 1][y] < a[x][y])
        m = max(m, dp(x + 1, y));
    if (y + 1 < col && a[x][y + 1] < a[x][y])
        m = max(m, dp(x, y + 1));
    r[x][y] = m + 1;
    return m + 1;
}

void print() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) 
            printf("%d ", r[i][j]);
        printf("\n");
    }
}

int main(){
    scanf("%d %d", &row, &col);
    for (int i = 0; i < row; i++) 
        for (int j = 0; j < col; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < row; i++) 
        for (int j = 0; j < col; j++)
            dp(i, j);

    int m = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (r[i][j] > m)
                m = r[i][j];
        }
    }

    printf("%d\n", m);
    return 0;
}
