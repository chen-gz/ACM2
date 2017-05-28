//快速乘
ll multi(ll a, ll b, ll m)
{
	ll ans = 0;
	while (b)
	{
		if (b & 1) (ans += a) %= m;
		(a = a * 2) %= m;
		b /= 2;
	}
	return ans;
}