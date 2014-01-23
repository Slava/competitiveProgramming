for (int k = 0; k < N; k++)
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
