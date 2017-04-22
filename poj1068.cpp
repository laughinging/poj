#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int p[100];
char s[200];

int main(){
    int t;
    cin >> t;
    while (t--){
        int n; cin >> n;
        int i = 0, l = 0;
        while (n--) {
            int v; cin >> v;
            int k = v - l;
            while (k) {
                s[i++] = '(';
                l++;
                k--;
            }
            s[i++] = ')';
        }
        s[i++] = '\0';

        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') continue;
            int lc = 0, rc = 0;
            for (int j = i; j >=0; j--) {
                if (s[j] == '(') 
                    lc ++;
                else rc ++;
                if (lc == rc) break;
            }
            cout << rc;
            if (i != len -1) cout << ' ';
        }  
        cout << endl;
    }


    return 0;
}
