#include <cstdio>
#include <string>

typedef std::string str;
const int N = 110;
char st[N], pair[] = "()[]";
str s[N][N], S, addl, addr;
int a[N][N], n, pp[256];

int main (){
	if(scanf("%s", st) != 1)return 0;
	S = st;	n = S.size();
	for (int i = 0; i < 4; i++)pp[pair[i]] = i;
	for (int i = 0; i < n; i++){
		a[i][i] = 1;
		if (S[i] == '(' || S[i] == ')') 
			s[i][i] = "()";
		else s[i][i] = "[]";
	}
	for (int j = 1; j < n; j++)for (int i = 0; i + j < n; i++){
		int l = i, r = i + j, L = l, R = r, flag;
		s[L][R] = addl = addr = "";a[L][R] = (1 << 30);
		for (;;){
			flag = 0;
			if (r < l){
				flag = 1; a[L][R] = 0; s[L][R] = "";
			}
			if (l == r){
				flag = 1;a[L][R] = 1;
				if (S[l] == '(' || S[l] == ')')
					s[L][R] = "()";
				else s[L][R] = "[]";
			}else
			for (int k = l; k < r; k++)
				if (a[L][R] > a[l][k] + a[k + 1][r]){
					a[L][R] = a[l][k] + a[k + 1][r];
					flag = 1;
					s[L][R] = s[l][k] + s[k + 1][r];
				}
			if (flag)
				s[L][R] = addl + s[L][R] + addr;
			if (l <= r && ((S[l] == '(' && S[r] == ')') || (S[l] == '[' && S[r] == ']'))){
				addl = addl + S.substr(l, 1);
				addr = S.substr(r, 1) + addr;
				l++, r--;
			}else break;
		}
	}
//	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)printf("%d=>%s%c", a[i][j], s[i][j].c_str(), " \n"[j == n - 1]);
	printf("%s\n", s[0][n - 1].c_str());
	return 0;
}

