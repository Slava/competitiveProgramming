#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int kmp (string s){
	vector<int>pi(s.size());
	reverse(s.begin(), s.end());
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

int main (){
	string S;
	char s[5100];
	int ans = 0;
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++){
		S.push_back(s[i]);
		ans += kmp(S);
	}
	printf("%d", ans);
	return 0;
}

