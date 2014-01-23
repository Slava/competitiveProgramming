#include <cstdio>
#include <cstring>
int k, m, a[10009], l, b, sum, i;
char s[10009];
int main () {
freopen("A.in","r",stdin);
freopen("A.out","w",stdout);
scanf("%d %d %s", &k, &m, s);
l = strlen(s);
a[l - 1] = 1;
for (i = l - 2; i >= 0; i--)
a[i] = ( a[i + 1] * k ) % m;
for (i = 0; i < l; i++) {
if (s[i] >= 'A' && s[i] <= 'Z')
b = s[i] - 55;
if (s[i] <= '9' && s[i] >= '0')
b = s[i] - 48;
sum = (sum + b * a[i]) % m;
}
printf("%d", sum);
}
