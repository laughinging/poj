#include <iostream>
#include <cstdio>
#include <cstring> // memset
#include <algorithm> // sort
using namespace std;

int m[10];
string a[20];

string n2s(int n) {
    string t = "";
    while (n > 0) {
        t.insert(t.begin(), n%10+'0');
        n /= 10;
    }
    return t;
}

string f(string str) {
    memset(m, 0, sizeof(m));
    int l = str.length();
    for (int i = 0; i < l; i++) {
        m[str[i]-'0'] += 1;
    }
    string t = "";
    for (int i = 0; i < 10; i++) {
        if (m[i] != 0) {
            t += n2s(m[i]);
            t += i + '0';
        }
    }
    return t;
}

void work(string str) {
    a[0] = str;
    for (int i = 1; i < 16; i ++) {
        a[i] = f(a[i-1]);
        //cout << a[i] << endl;
    }
    if (a[0] == a[1]) {
        cout << str << " is self-inventorying" << endl;
        return;
    }
    for (int i = 1; i < 16; i++) {
        if (a[i] == a[i-1]) {
            cout << str << " is self-inventorying after " << i-1 << " steps" << endl;
            return;
        }
    }
    for (int i = 0; i < 15; i ++) {
        for (int j = i+1; j < 16; j++) {
            if (a[i] == a[j]) {
                cout << str << " enters an inventory loop of length " << j-i << endl;
                return;
            }
    
        }
    }
    cout << str << " can not be classified after 15 iterations" << endl;
    return;
}

int main() {
    string s;
    while (cin >> s) {
        if (s[0] == '-') 
            break;
        work(s);
    }
    return 0;
}
