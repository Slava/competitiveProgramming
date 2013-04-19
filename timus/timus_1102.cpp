#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string str;
char s[10101010];
int solve (){
	scanf("%s", s); str = s;
	reverse(str.begin(), str.end());
	for (int i = 0; i < str.size(); i++){
		if (i + 6 <= str.size() && "tuptuo" == str.substr(i, 6))
			i += 5;
		else if (i + 5 <= str.size() && "tupni" == str.substr(i, 5))
			i += 4;
		else if (i + 5 <= str.size() && "notup" == str.substr(i, 5))
			i += 4;
		else if (i + 3 <= str.size() && ("tuo" == str.substr(i, 3) || "eno" == str.substr(i, 3)))
			i += 2;
		else if (i + 2 <= str.size() && "ni" == str.substr(i, 2))
			i++;
		else{//printf("%d %c ", i, str[i]);
			puts("NO");
			return 0;
		}
	}puts("YES");
	return 0;
}

int main (){
	int t;
	for (scanf("%d", &t); t--; )
		solve();
	return 0;
}

