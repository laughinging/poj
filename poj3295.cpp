#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>

using namespace std;

char str[110];
int p, q, r, s, t;
int cal() {
    stack<int> st;
    int l = strlen(str);
    for (int i = l - 1; i >=0; i--) {
        if (str[i] == 'p') st.push(p);
        if (str[i] == 'q') st.push(q);
        if (str[i] == 'r') st.push(r);
        if (str[i] == 's') st.push(s);
        if (str[i] == 't') st.push(t);
        if (str[i] == 'N') {
            int t = st.top();
            st.pop();
            st.push(t ^ 1);
        }
        int t1, t2;
        if (str[i] == 'K' || str[i] == 'A' || str[i] == 'C' || str[i] == 'E') {
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();
        }
        if (str[i] == 'K') st.push(t1 & t2);
        if (str[i] == 'A') st.push(t1 | t2);
        if (str[i] == 'C') {
            if (t1 == 1 && t2 == 0)
                st.push(0);
            else st.push(1);
        } 
        if (str[i] == 'E') {
            if (t1 == t2)
                st.push(1);
            else st.push(0);
        }
    }
    return st.top();
}

bool tautology(){
    for (p = 0; p < 2; p++)
        for (q = 0; q < 2; q++)
            for (r = 0; r < 2; r++)
                for (s = 0; s < 2; s++)
                    for (t = 0; t < 2; t++)
                        if (cal() == 0)
                            return false;
    return true;
}

int main(){
    while (cin >> str) {
        if (str[0] == '0') break;
        if (tautology())
            cout << "tautology" << endl;
        else
            cout << "not" << endl;
    }

    return 0;
}
