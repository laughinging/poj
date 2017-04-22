#include <iostream>
#include <cstdio>
#include <cstring> 
#include <algorithm> 
#include <queue>

using namespace std;

bool vis[100010];
struct node{
    int x, time;
};
queue<node> q;


int main() {
    int n, k;
    cin >> n >> k;
    node t = {n, 0};
    q.push(t);
    vis[n] = true;

    while (true) {
        if (q.empty())
            return -1;
        t = q.front();
        q.pop();
        if (t.x == k) {
            cout << t.time << endl;
            return 0;
        } 
        if (t.x <= 99999 && !vis[t.x+1]) {
            node v = {t.x+1, t.time+1};
            vis[t.x+1] = true;
            q.push(v);
        }
        if (t.x >= 1 && !vis[t.x-1]) {
            node v = {t.x-1, t.time+1};
            vis[t.x-1] = true;
            q.push(v);
        }
        if (t.x < 50001 && !vis[t.x*2]) {
            node v = {t.x*2, t.time+1};
            vis[t.x*2] = true;
            q.push(v);
        }
    }
    return 0;
}
