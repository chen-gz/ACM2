//第二类Stirling数
void init()
{
	for (int i = 1; i < MAXN; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (i == j || j == 1) s[i][j] = 1;
			else if (i > 1) s[i][j] = (j * s[i - 1][j] % MOD + s[i - 1][j - 1]) % MOD;
		}
	}
}
