#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    int check[12][3];
    int res[3];
    int n;
    cin >> n;

    while (n--) {
        memset(check, 0, sizeof(check));
        memset(res, 0, sizeof(res));

        string a, b, c;
        for (int i = 0; i < 3; i++) {
            cin >> a >> b >> c;
            for (int j = 0; j < a.size(); j++) {
                check[a[j] - 'A'][i] = 1;
                check[b[j] - 'A'][i] = -1;
            }
            if (c=="down") res[i] = -1;
            if (c=="up") res[i] = 1;
        }

        for (int i = 0; i < 12; i ++) {
            if (check[i][0] == res[0] && check[i][1] == res[1] && check[i][2] == res[2]) {
                cout << char('A' + i) << " is the counterfeit coin and it is heavy." << endl;
                break;
            }
            if (check[i][0] == -res[0] && check[i][1] == -res[1] && check[i][2] == -res[2]) {
                cout << char('A' + i) << " is the counterfeit coin and it is light." << endl;
                break;
            }
        }
    }
    return 0;
}
