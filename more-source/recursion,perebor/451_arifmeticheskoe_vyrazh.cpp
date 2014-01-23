#include <cstdio>
#include <cmath>
#include <cstring>
double v;
int p, curlex, i, l;
char s[999];
bool A(char );
void nextlexem();
double expr();
double item();
double mult();
int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    double a;
    gets(s);
    l = strlen(s);
    nextlexem();
    a = expr();
    if (p == 0 && i == l + 1) printf("%lf", a);
    else printf("Error");
}
bool A(char z) {
    return (z >= '0' && z <= '9');
}
void nextlexem() {
    curlex = 0;
    while (s[i] == ' ') i++;
    if (s[i] == '+') curlex = 1;
    if (s[i] == '*') curlex = 2;
    if (A(s[i])) {
        curlex = 3;
        for (v = 0; A(s[i]); i++)
            v = v * 10 + (s[i] - 48);
        if (s[i] == '.')  {
            i++;
            double b;
            for (b = 10; A(s[i]); i++, b *= 10)
                v += (s[i] - 48) / b;
        }
        i--;
    }
    if (s[i] == '(') curlex = 4;
    if (s[i] == ')') curlex = 5;
    if (s[i] == '-') curlex = 7;
    if (s[i] == '/') curlex = 8;
    if (s[i] == 's') {
        i += 3;
        curlex = 9;
    }
    if (s[i] == 'c') {
        i += 3;
        curlex = 6;
    }
    i++;
}
double mult() {
    double a;
    if (curlex == 3) {
        a = v;
        nextlexem();
    }
    else {
        if (curlex == 4) {
            nextlexem();
            a = expr();
            if (curlex == 5)
                nextlexem();
            else p = 1;
        }
        else {
            if (curlex == 9 || curlex == 6) {
                if (curlex == 9) {
                    nextlexem();
                    a = sin(expr());
                }
                if (curlex == 6) {
                    nextlexem();
                    a = cos(expr());
                }
                if (curlex == 5)
                    nextlexem();
                else p = 1;
            }
            else {
                if (curlex == 7) {
                    nextlexem();
                    a = -item();
                }
                else p = 1;
            }
        }
    }
    return a;
}
double item() {
    double a;
    a = mult();
    while (curlex == 2 || curlex == 8) {
        if (curlex == 2) {
            nextlexem();
            a *= mult();
        }
        if (curlex == 8) {
            nextlexem();
            a = a / mult();
        }
    }
    return a;
}
double expr() {
    double a;
    a = item();
    while (curlex == 1 || curlex == 7) {
        if (curlex == 1) {
            nextlexem();
            a += item();
        }
        if (curlex == 7) {
            nextlexem();
            a -= item();
        }
    }
    return a;
}
