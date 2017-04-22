#include <iostream>
#include <cstdio>
#include <cstring> // memset
#include <algorithm> // sort
#include <map>
#include <string>

using namespace std;

bool sup(string s) {
    map<string, int> m;
    int l = s.length();
    for (int i = 0; i < l-1; i++) {
        m.clear();
        for (int j = 0; j < l-i-1; j++) {
            string t="";
            t += s[j];
            t += s[j+i+1];
            if (m[t] == 1) {
                return false;
            }
            m[t] = 1;
        }
    }
    return true;
}


int main() {
    string s;
    while (cin >> s) {
        if (s[0] == '*')
            break;
        cout << s << " is" << (sup(s) ? "" : " NOT") << " surprising." << endl;
    }
    
    
    return 0;
}
