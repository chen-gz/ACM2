//普通快速幂
#include <vector>
#include <cassert>
typedef long long ll;
ll mod_pow(ll x, ll n, ll mod) {
	ll ans = 1;//返回的值,x的n次方
	while (n) {
		if (n & 1)
			ans = (ans * x) % mod; // 奇数位
		x = x*x%mod; // 每位都平方
		n >>= 1; // 右移
	}
	return ans;
}
//矩阵快速幂
//要取模自己写
const int MatSize = 100;
class Mat {
public:
long long value[MatSize][MatSize];
Mat operator * (Mat b) const {
	Mat ans;
	memset(ans.value, 0, sizeof(ans.value));
	for (int i = 0; i < MatSize; i++) {
		for (int j = 0; j < MatSize; j++) {
			for (int k = 0; k < MatSize; k++) {
				ans.value[i][j] += this->value[i][k] * b.value[k][j];
			}
		}
	}
	return ans;
};
Mat() {
};
Mat(int identity) {
	//传1变成单位矩阵
	for (int i = 0; i < MatSize; i++) {
		this->value[i][i] = 1;
	}
};
};
Mat MatPower(Mat x, int n) {
	Mat ans;//返回的值,x的n次方
	while (n) {
		if (n & 1)
			ans = (ans * x); // 奇数位
		x = x*x; // 每位都平方
		n >>= 1; // 右移
	}
	return ans;
}
