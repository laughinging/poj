#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
stack<string> f;
stack<string> b;
string c;

int main() {
    string current = "http://www.acm.org/";
    b.push(current);
    while (cin >> c) {
        if (c == "QUIT") break;
        if (c == "BACK") {
            if (b.size() >= 2) {
                f.push(b.top());
                b.pop();
                cout << b.top() << endl;
            } else {
                cout << "Ignored" << endl;
            }
        } else if (c == "FORWARD") {
            if (!f.empty()) {
                cout << f.top() << endl;
                b.push(f.top());
                f.pop();
            } else {
                cout << "Ignored" << endl;
            }
        } else if (c == "VISIT") {
            cin >> current;
            cout << current << endl;
            b.push(current);
            while (!f.empty()) f.pop();
        }
    }
    return 0;
}
