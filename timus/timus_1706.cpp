#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int kmp (string s, bool r = 0){
	vector<int>pi(s.size());
	if(r)reverse(s.begin(), s.end());
	pi[0] = 0;
	int j, i, mx = 0;
	for (i = 1; i < s.size(); i++){
		j = pi[i - 1];
		while(j > 0 && s[j] != s[i])
			j = pi[j - 1];
		if (s[i] == s[j])j++;
		pi[i] = j;
		mx = max(j, mx);
	}
	return s.size() - mx;
}

char str[4100];
int main (){
	int ans = 0, n, k;
	scanf("%d%s", &k, str);
	string s = str; n = s.size(); s += s;
	for (int i = 1; i <= k; i++)
		ans += kmp(s.substr(0, i), 1);
	printf("%d ", ans);
	for (int i = 1; i < n; i++){
		ans -= kmp(s.substr(i - 1, k));
		ans += kmp(s.substr(i, k), 1);
		printf("%d ", ans);
	}
	return 0;
}

