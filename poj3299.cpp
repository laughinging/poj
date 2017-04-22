#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    char x, y;
    double t = 0, d = 0, h = 0;
    while (true) {
        scanf("%c ", &x);
        switch (x) {
            case 'E' : return 0;
            case 'T' : scanf("%lf ", &t);
            case 'D' : scanf("%lf ", &d);
            case 'H' : scanf("%lf ", &h);
        }
        scanf("%c ", &y);
        switch (y) {
            case 'T' : scanf("%lf\n", &t);
            case 'D' : scanf("%lf\n", &d);
            case 'H' : scanf("%lf\n", &h);
        }

        if ((x == 'T' && y == 'D') || (x == 'D' && y == 'T'))
            h = t + 0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10.0);
        if ((x == 'H' && y == 'D') || (y == 'H' && x == 'D'))
            t = h - 0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10.0);
        if ((x == 'T' && y == 'H') || (y == 'T' && x == 'H'))
            d = 1/(1/273.16-log(((h-t)/0.5555+10.0)/6.11)/5417.7530)-273.16;

        printf("T %.1f D %.1f H %.1f\n", t, d, h);
    }
    return 0;
}
