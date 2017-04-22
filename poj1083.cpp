#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int room[210];

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i ++) {
        int N;
        cin >> N;
        memset(room, 0, sizeof(room));
        for (int j = 0; j < N; j ++) {
            int a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            if (a & 1) a ++;
            if (b & 1) b ++;
            for (int k = a/2; k <= b/2; k++)
                room[k] ++;
        }
        int m = 0;
        for (int j = 1; j <= 200; j++)
            if (room[j] > m)
                m = room[j];
        cout << m * 10 << endl;
    }


    return 0;
}
