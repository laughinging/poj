#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

string Tzolkin[20] = {"ahau", "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik",
    "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban",
    "eznab", "canac"}; 

string Haab[18] = { "pop", "no", "zip", "zotz",
        "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac",
        "kankin", "muan", "pax", "koyab", "cumhu" };

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        string m;
        int d, y; 
        scanf("%d. ", &d);
        cin >> m; 
        scanf("%d",&y);
        int j;
        for (j = 0; j < 18; j++)
            if (m == Haab[j])
                break;
        int s = j * 20 + y * 365 + d + 1;
        y = (s - 1) / 260;
        int k = s - y * 260;
        int mo = k % 20;
        k %= 13;
        if (k == 0)
            k = 13;

        cout << k << ' ' << Tzolkin[mo] << ' ' << y << endl;
    }
    return 0;
}
