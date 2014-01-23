#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <sstream>

using namespace std;

typedef long long i64;


#define WA 1
#define PE 2
#define OK 0
#define JE 4

char s[10000];
int a[100], b[100], c[100];

void exit(int code, const char *msg) {
	fprintf(stderr, "%s\n", msg);
	exit(code);
}

void OK2()
{
   FILE *f = fopen("points", "r");
   int cpoints=0;
   if (f != 0)
   {
      fscanf(f, "%d", &cpoints);
      fclose(f);
   }

   f = fopen("points","w");
   fprintf(f,"%d\n",cpoints+1);
   fclose(f);
   fprintf(stderr,"OK!\n");
   exit(0, "OK");
}

int main(int argc, char *argv[]) {
	FILE *in = fopen(argv[1], "rt");
	FILE *out = fopen(argv[3], "rt");
	FILE *ans = fopen(argv[2], "rt");
	
	int n, m, k;
	fscanf(in, "%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		fscanf(in, "%d", &a[i]);
	}
	for (int i = 0; i < m; ++i) {
		fscanf(in, "%d", &b[i]);
	}
	fgets(s, 10000, in);
	for (int i = 0; i < m; ++i) {
		fgets(s, 10000, in);
		istringstream sin(s);
		int x;
		while (sin >> x) {
			c[i] |= 1 << (x - 1);
		}
	}
	int y = 0;
	int x;
	i64 K = 0;
	while (fscanf(out, "%d", &x) == 1) {
		--x;
		if (x < 0 || x >= n) {
			exit(WA, "Invalid item");
		}
		if (y & (1 << x)) {
			exit(WA, "Duplicate item");
		}
		y |= 1 << x;
		K += a[x];
	}
	if (K > k)exit(WA, "Snack overflow");
	i64 ro = 0;
	for (int i = 0; i < m; ++i) {
		if ((c[i] & y) == c[i]) {
			ro += b[i];
		}
	}
	y = 0;
	while (fscanf(ans, "%d", &x) == 1) {
		--x;
		y |= 1 << x;
	}
	i64 ra = 0;
	for (int i = 0; i < m; ++i) {
		if ((c[i] & y) == c[i]) {
			ra += b[i];
		}
	}
	if (ro < ra) exit(WA, "Not optimal");
	OK2();
	return 0;
}
