#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

const char DIRECTION[4] = "NESW";

struct pos{
    int x, y, dir;
};

struct robot{
    vector<pos> postion;
    int crash_to_wall = -1;
};

robot r[110];

struct move{
    int r, rep;
    char m;
}

move m[110];

void cg(move b) {
    if (r[b.r].crash_to_wall != -1) return;

    while (b.rep --) {
        if (b.m == 'L') {
            r[b.r].dir = (r[b.r].dir - 1) % 4; 
        }
        if (b.m == 'R') {
            r[b.r].dir = (r[b.r].dir + 1) % 4;
        }
        if (b.m == 'F') {
            int x = 
        }


    }
}

int main(){
    int test; cin >> test;
    while (test--) {
        int col, row; cin >> col >> row;
        int nRobot, nMove; cin >> nRobot >> nMove;
        for (int i = 0; i < nRobot; i++) {
            char d;
            cin >> r[i].x >> r[i].y >> d;
            r[i].d = strchr(DIRECTION, d) - DIRECTION;
        }
        
        

    }


    return 0;
}
