// Kim Vyacheslav
// Karaganda KTL
// 15.03.2011
#include <cstdio>
#include <queue>

using namespace std;

queue<int>q;
const int N = 1000100;
int a[N], A, B, C, D, E, x;
char from[N + 1], ans[N + 1];
const int inf = 1e7;

int main ()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    scanf("%d%d%d%d%d", &A, &B, &C, &D, &E);
    for (int i = 1; i < N; i++)
        a[i] = inf;
    q.push(0);
    while (!q.empty())
    {
        x = q.front();
		if (x == E)break;
//        printf("x=%d * %d + %d / %d - %d\n", x, x *A, x +B, x / C, x - D);
        q.pop();
        if (x * A < N && a[x * A] > a[x] + 1)
            q.push(x * A), a[x * A] = a[x] + 1, from[x * A] = '*';
        if (x + B < N && a[x + B] > a[x] + 1)
            q.push(x + B), a[x + B] = a[x] + 1, from[x + B] = '+';
        if (x % C == 0 && a[x / C] > a[x] + 1)
            q.push(x / C), a[x / C] = a[x] + 1, from[x / C] = '/';
        if (x - D > 0 && a[x - D] > a[x] + 1)
            q.push(x - D), a[x - D] = a[x] + 1, from[x - D] = '-';
    }

//    printf("%d\n", a[E]);
    if (a[E] != inf){
        for (int x = E, i = 0; x; i++)
        {
            ans[i] = from[x];
            switch(from[x])
            {
                case '+':
                    x -= B;
                    break;
                case '-':
                    x += D;
                    break;
                case '*':
                    x /= A;
                    break;
                case '/':
                    x *= C;
                    break;
            }
        }
        for (int i = a[E] - 1; i >= 0; i--)
            printf("%c", ans[i]);
    }
    else puts("Impossible");
    return 0;
}

