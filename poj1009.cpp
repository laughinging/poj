#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int width;
int height;
int nPix;
int n;

struct Pix{
    int v;
    int l;
};

struct info{
    int pos;
    int v;
};

Pix image[1010];
info out[10000];

int get_v(int pos) {
    int i = 0, s = image[i].l;
    while (pos > s) {
        s += image[++i].l;
    }
    return image[i].v;
}

int get_output(int pos) {
    int row = (pos - 1) / width;
    int col = (pos - 1) % width;
    int t = get_v(pos);
    int mx = 0;

    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i < 0 || j < 0 || i >= height || j >= width)
                continue;
            int p = i * width + j + 1;
            int s = get_v(p);
            if (mx < abs(s - t))
                mx = abs(s - t);
        }
    }
    return mx;
}

int cmp(info a, info b) {
    return a.pos < b.pos;
}

void treat(int pos) {
    int row = (pos - 1) / width;
    int col = (pos - 1 ) % width;
    
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j ++) {
            if (i < 0 || j < 0 || i >=height || j >= width)
                continue;

            int u = i * width + j + 1;
            out[n].pos = u;
            out[n++].v = get_output(u);
        }
    }
}

int main(){
    while (true) {
        cin >> width;
        if (width == 0) break;

        cout << width << endl;
        memset(out, 0, sizeof(out));
        memset(image, 0, sizeof(image));
        height = 0;

        nPix = 0;
        while (true) {
            int a, b;
            cin >> a >> b;
            if (a == 0 && b == 0) break;
            image[nPix].v = a;
            image[nPix].l = b;
            nPix ++;
            height += b;
        }

        height /= width;
        
        int pos = 1;
        n = 0;
        treat(1);
        for (int i = 0; i < nPix; i++) {
            pos += image[i].l;
            int row = pos / width;
            int col = pos % width;
            treat(pos);
        }

        sort(out, out + n, cmp);

        info t = out[0];
        for (int i = 1; i < n; i++) {
            if (t.v == out[i].v)
                continue;
            cout << t.v << ' ' << out[i].pos - t.pos << endl;
            t = out[i];
        }

        cout << t.v << ' ' << width * height - t.pos + 1 << endl;
        cout << "0 0" << endl;
    }
    cout << 0 << endl;
    return 0;
}
