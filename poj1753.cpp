#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct Node{
    int state;
    int last;
    int step;
};

bool visit[65536];

int m[16] = {
    0xc800, 0xe400, 0x7200, 0x3100, 
    0x8c80, 0x4e40, 0x2720, 0x1310, 
    0x8c8, 0x4e4, 0x272, 0x131, 
    0x8c, 0x4e, 0x27, 0x13
};

queue <Node> q;

int bfs(int state){
    memset(visit, false, sizeof(visit));
    Node x;
    x.state = state;
    x.last = -1;
    x.step = 0;
    q.push(x);

    Node cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        visit[cur.state] = true;
        if (cur.state == 0 || cur.state == 0xffff) 
            return cur.step;

        for (int i = cur.last + 1; i < 16; i++) {
            int s = cur.state ^ m[i];
            if (!visit[s]) {
                Node v;
                v.step = cur.step + 1;
                v.last = i;
                v.state = s;
                q.push(v);
            }
        }
    }
    return -1;
}

int main(){
    int s = 0;
    char a;
    while (true){
        a = getchar();
        if (a == 'b')
            s = (s << 1) + 1;
        if (a == 'w')
            s = s << 1;
        if (a == EOF) break;
    }
    int t = bfs(s);
    if (t == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << t << endl;
    }

    return 0;
}
