#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

struct island {
    double x, y, left, right;
} x[1010];

int cmp(island a, island b) {
    return a.right < b.right;
}

double d;

bool in_circle(island a, double c) {
    return a.left - c < 1e-5 && c - a.right  < 10e-5;
}

int a;
int main(){
    while (true) {
        int n;
        cin >> n >> d;
        if (n == 0 && d < 1e-5) break;
        a ++;

        bool flag = false;
        for (int i = 0; i < n; i++) {
            cin >> x[i].x >> x[i].y;
            if (x[i].y > d) flag = true;
        }

        if (flag) {
            cout << "Case " << a << ": -1" << endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            double z = sqrt(d * d * 1.0 - x[i].y * x[i].y * 1.0);
            x[i].left = (double) x[i].x - z;
            x[i].right = (double) x[i].x + z;
        }
        sort(x, x+n, cmp);

        int ans = 1;
        double t = x[0].right;

        for (int i = 1; i < n; i++) {
            if (in_circle(x[i], t)) continue;
            ans ++;
            t = x[i].right;
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
