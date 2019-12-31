//普通快速幂
#include <vector>
#include <cassert>

template<typename T>
T mod_pow(T base, T exponent, T module) {
    T ans = 1;
    while (exponent) {
        if (exponent & 1)
            ans = (ans * base) % module;
        base = base * base % module;
        exponent >>= 1;
    }
    return ans;
};
//矩阵快速幂
//要取模自己写
const int MatSize = 100;
class Mat {
public:
	long long value[MatSize][MatSize];
	Mat operator * (Mat &b) const {
		Mat ans;
		memset(ans.value, 0, sizeof(ans.value));
		for (int i = 0; i < MatSize; i++) {
			for (int j = 0; j < MatSize; j++) {
				for (int k = 0; k < MatSize; k++) {
					ans.value[i][j] += (this->value[i][k] * b.value[k][j]) % MOD;
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
			for (int j = 0; j < MatSize; j++) {
				this->value[i][j] = 0;
			}
		}
		for (int i = 0; i < MatSize; i++) {
			this->value[i][i] = 1;
		}
	};
};
Mat MatPower(Mat x, int n) {
	Mat ans(1);//返回的值,x的n次方
	while (n) {
		if (n & 1)
			ans = (ans * x); // 奇数位
		x = x * x; // 每位都平方
		n >>= 1; // 右移
	}
	return ans;
}





////////////////别人的矩阵快速幂
struct mat {
	ll a[3][3];
	void init() {
		memset(a, 0, sizeof(a));
		a[0][0] = a[1][1] = a[2][2] = 1;
	}
	mat operator *(const mat &b) {
		mat t;
		t.init();
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				t.a[i][j] = 0;
				for (int k = 0; k < 3; ++k) {
					t.a[i][j] = (t.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
				}
			}
		}
		return t;
	}
};
mat powmod(mat x, int b) {
	mat r;
	r.init();
	while (b) {
		if (b & 1) {
			r = r * x;
		}
		x = x * x;
		b >>= 1;
	}
	return r;
}