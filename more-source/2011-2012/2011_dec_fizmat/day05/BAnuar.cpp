#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct T {
    double x, y;
};

int n, i, j, k, l;
T p[2009];
double ans;

double area(T a, T b, T c) {
    long long la = b.y - a.y,
        lb = a.x - b.x,
        lc = -la * a.x - lb * a.y;
    double h = fabs((la * c.x + lb * c.y + lc)) / sqrt(la * la + lb * lb + .0);
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)) * h / 2;
}

double search(T a, T b) {
    int l = 1, r = n;
    if(r - l == 2) {
        return area(a, b, p[(l + r) / 2]);
    }
    while(r - l > 2) {
        int dif = (r - l) / 3;
        int tl = l + dif, tr = r - dif;
        double f1 = area(a, b, p[tl]), f2 = area(a, b, p[tr]);
//        printf("%d %d %.4lf %.4lf\n", l, r, f1, f2);
        ans = max(ans, max(f1, f2));
        if(f1 > f2)
            l = tl;
        else
            r = tr;
    }
    return max(area(a, b, p[l]), (r - l == 2) ? area(a, b, p[(l + r) / 2]) : 0);
}

int main() {
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(i == j) continue;
            ans = max(ans, search(p[i], p[j]));
        }
    }
    printf("%.10lf", ans);
}
