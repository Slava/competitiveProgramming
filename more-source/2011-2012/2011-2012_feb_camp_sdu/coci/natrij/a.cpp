#include <cstdio>

int h, m, s, hh, mm, ss, ans;
int main() {
	scanf("%d:%d:%d\n%d:%d:%d", &h, &m, &s, &hh, &mm, &ss);
	if (h < hh || (h == hh && m < mm) || (h == hh && m == mm && s < ss)) {
		ans = hh*3600+mm*60+ss-(h*3600+m*60+s);
	} else {
		ans = 3600*24 + hh*3600+mm*60+ss-(h*3600+m*60+s);
	}

	printf("%02d:%02d:%02d\n", ans/3600, (ans%3600)/60, ans%60);
	return 0;
}

