#include <cstdio>
#include <iostream>

int abs (int x){
	if (x < 0)
		return - x;
	else return x;
}

int a[500], b[500], n, ans, ans1;
bool check()
{
	for (int i = 1; i < n; i++)
		if (abs(a[i] - a[i - 1]) > 1)
			return 0;
	return 1;
}
int main()
{
	std::cin >> n;
	for (int i = 0; i < n; i++){
		std::cin >> a[i];
		b[i] = a[i];
	}
	while(!check()){
		int mx = -1;
		for (int i = 1; i < n; i++)
			if (abs(a[i] - a[i - 1]) > 1){
				if (mx == -1 || a[mx] < a[i])
					mx = i;
				if (mx == -1 || a[mx] < a[i - 1])
					mx = i - 1;}
		if (mx && mx != n - 1)
			if (a[mx - 1] < a[mx + 1])
				a[mx - 1]++;
			else a[mx + 1]++;
		else if (mx)a[mx - 1]++;
			else a[mx + 1]++;
		a[mx]--;
		ans1++;
	}
	for (int i = 0; i < n; i++)
		a[i] = b[i];
	while (!check()){
		int mx = -1;
		for (int i = 1; i < n; i++)
			if (abs(a[i] - a[i - 1]) > 1){
				if (mx == -1 || a[mx] > a[i])
					mx = i;
				if (mx == -1 || a[mx] > a[i - 1])
					mx = i - 1;}
		if (mx && mx != n - 1)
			if (a[mx - 1] > a[mx + 1])
				a[mx - 1]--;
			else a[mx + 1]--;
		else if (mx)a[mx - 1]--;
			else a[mx + 1]--;
		a[mx]++;
		ans++;
	}
	std::cout << std::min(ans1,ans);
	return 0;
}
