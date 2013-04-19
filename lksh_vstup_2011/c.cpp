#include <cstdio>
#include <iostream>
typedef long long ll;

int n, state[20], staten;
ll a[20], num, ans, sum;
char s[20];

main ()
{
	std::cin >> s;
	for(; s[n]; n++);
	for (int i = 0; i < n; i++)if(s[i] == '*')
		state[i] = staten++;
	for (int m = 0; m < (1 << staten); m++){
		ans = 1; a[0] = 1; num = 1;
		for (int i = 0, j = 0; i < n; i++){
			if (s[i] == 'S' || (s[i] == '*' && ((m >> state[i]) & 1) == 0))
				continue;
			else if (s[i] == '*' && (m >> state[i]) & 1){
				ans *= 3;
				a[j + 1] = a[j] * 9 + num * 3;
				num *= 3;
			}
			else if (s[i] == 'L' || s[i] == 'R' || s[i] == 'C'){
				a[j + 1] = a[j] * 3;
				if (s[i] == 'C')
					a[j + 1] += num;
				if (s[i] == 'R')
					a[j + 1] += num * 2; 
			}
			j++;
			ans += a[j], a[j + 1] = 0;
		}
		sum += ans;
	}
	std::cout << sum;
}

