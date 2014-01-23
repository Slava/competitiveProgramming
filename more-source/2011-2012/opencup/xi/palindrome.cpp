void upd(int &a, int b) {
	if (b > a)
		a = b;
}

const int N = 100;
const int L = 1010;
int n, len[N];
int inf = 1000000000;
char s[L+L], store[N][L];
int z[N][N][L], z1[N][N][L], Z[L+L];

void z_func(char *s, int *to) {
	int n = strlen(s), j, l, r, st=-1;
	memset(Z,0,sizeof Z);
	Z[0] = 0; l = r = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == '$')
			st = i+1;
		if (i > r) Z[i] = 0;
		else {
			j = i - l;
			if (Z[j] + j <= Z[l])
				Z[i] = Z[j];
			else Z[i] = r - i + 1;
		}
		while (i + Z[i] < n && s[i + Z[i]] == s[Z[i]])
			Z[i]++;
		if (i + Z[i] > r)
			l = i, r = i + Z[i] - 1;
	}
	for (int i = st; i < n; i++)
		to[i-st]=Z[i];
	reverse(to,to+n-st);
}

// flag{left,right}, which, pos
int dp[2][N][L];
char was[2][N][L];
int go(int fl, int wh, int Len) {
	int &res = dp[fl][wh][Len];
	char &Was = was[fl][wh][Len];
	if (Was == 1) {
		puts("-1");
		exit(0);
	}
	if (Was == 2) {
		return res;
	}

	Was = 1; res = 0;
	// add to left
	if (fl) {
		for (int i = 0; i < n; i++) {
			if (!Len || (len[i] >= Len && z[wh][i][Len-1] == Len))
				upd(res, go(0,i,len[i]-Len)+2*Len);
			if (len[i] < Len && z[i][wh][Len-1] == len[i])
				upd(res, go(1,wh,Len-len[i])+2*len[i]);
			upd(res,2*z[i][wh][Len-1]);
		}
	} else {	//add right
		for (int i = 0; i < n; i++) {
			if (!Len || (len[i] >= Len && z1[wh][i][Len-1] == Len))
				upd(res, go(1,i,len[i]-Len)+2*Len);
			if (len[i] < Len && z1[i][wh][Len-1] == len[i])
				upd(res, go(0,wh,Len-len[i])+2*len[i]);
			upd(res,2*z1[i][wh][Len-1]);
		}
	}

	Was = 2;
	return res;
}

void solve() {
#ifndef imslavko
	freopen("palindrome.in", "r", stdin);
	freopen("palindrome.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		strcat(store[i], s);
		len[i] = strlen(s);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			s[0] = 0;
			reverse(store[i],store[i]+len[i]);
			strcat(s,store[i]); strcat(s,"$");
			reverse(store[i],store[i]+len[i]);
			strcat(s,store[j]); z_func(s,z[i][j]);

			s[0] = 0; strcat(s, store[i]);
			strcat(s, "$");
			reverse(store[j],store[j]+len[j]);
			strcat(s, store[j]);
			reverse(store[j],store[j]+len[j]);
			z_func(s, z1[i][j]);
		}

	int best = 1;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < len[i]; j++) {
			for (int k=0; j-k>=0 && j+k<len[i] && store[i][j-k]==store[i][j+k];k++)
				upd(best,k+k+1);
			for (int k=0; j-k>=0 && j+k+1<len[i] && store[i][j-k]==store[i][j+k+1];k++)
				upd(best, k+k+2);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int k = 0;
			while (k < min(len[i]-1,len[j]) && store[j][k] == store[i][len[i]-k-2])
				k++;
			upd(best, k*2+1+((k==len[i]-1)?go(1,j,len[j]-k):((k==len[j])?go(0,i,len[i]-k-1):0)));
			k = 0;
			while (k < min(len[i],len[j]-1) && store[j][k-1] == store[i][len[i]-k-1])
				k++;
			upd(best, k*2+1+((k==len[i])?go(1,j,len[j]-k-1):((k==len[j]-1)?go(0,i,len[i]-k):0)));
		}
	for (int i = 0; i < n; i++) {
		for (int r = 0; r < len[i]; r++)
			if (z1[i][i][r] == r+1)
				upd(best, go(1,i,len[i]-r-1)+r+1);
		for (int l = 0; l < len[i]; l++)
			if (z[i][i][l] == l+1)
				upd(best, go(0,i,len[i]-l-1)+l+1);
		upd(best, max(go(1,i,len[i]),go(0,i,len[i])));
	}

	best = max(best, max(go(0,0,0),go(1,0,0)));
	printf("%d\n", best);
}
