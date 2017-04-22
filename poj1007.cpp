#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<map>
using namespace std;

int main(){
    map<int, string> x;
    int m, n;
    char d[110];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", d);
        int l = strlen(d);
        int A = 0, G = 0, C = 0;
        int s = 0;
        for (int j = l-1; j >= 0; j--) {
            switch(d[j]) {
                case 'A':
                    A ++;
                    break;
                case 'C':
                    C ++;
                    s += A;
                    break;
                case 'G':
                    G ++;
                    s += A + C;
                    break;
                case 'T':
                    s += A + C + G;
                    break;
            }
        }
        int order = s * 200 + i;
        x[order] = d;
    }


    for (map<int, string>::iterator p = x.begin(); p != x.end(); p++) {
        cout << p->second << endl;
    } 

    return 0;
}
