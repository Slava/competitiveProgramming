
const int N = 310;
int n, k;
double d[N][N];
int x[N], y[N], xx[1010], yy[1010];

void solve() {
#ifndef imslavko
	freopen("mines.in", "r", stdin);
	freopen("mines.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	double best = 1e19;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", x+i,y+i);
		for (int j = 0; j < n; j++)
			d[i][j] = 1e18;
	}
	for (int i = 0; i < k; i++)
		scanf("%d%d", xx+i,yy+i);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++) {
			bool neg = 0, pos = 0, ok = 1;
			int cx = x[i]-x[j], cy = y[i]-y[j];
			for (int l = 0; l < k; l++) {
				int sx = xx[l]-x[j], sy = yy[l]-y[j];
				int pr = cx * sy - cy * sx;
				pos |=  pr > 0;
				neg |= pr < 0;
				ok &= !pr;
				ok &= inBounds(xx[l],x[i],x[j]) || inBounds(xx[l],x[j],x[i]);
				ok &= inBounds(yy[l],y[i],y[j]) || inBounds(yy[l],y[j],y[i]);
			}
			double length = sqrt(cx*cx+cy*cy+.0);
			if (!neg && pos)
				d[i][j] = length;
			else if (neg && !pos)
				d[j][i] = length;
			if (ok)
				best = min(best, 2*length);
		}

	for (int l = 0; l < n; l++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				d[i][j] = min(d[i][l]+d[l][j], d[i][j]);
	for(int i = 0; i < n; i++)
		best = min(best, d[i][i]);
	if (best < 1e18) {
		printf("%.15lf\n", best);
	}else puts("-1");
}

