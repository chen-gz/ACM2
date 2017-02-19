#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

class Mat {
public:
    long long value[3][3];
    Mat operator * (Mat &b) const {
        Mat ans;
        memset(ans.value, 0, sizeof(ans.value));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
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
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                this->value[i][j] = 0;
            }
        }
        for (int i = 0; i < 3; i++) {
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



int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        int n;
        scanf("%d", &n);
        Mat x;
        x.value[0][0] = 1; x.value[0][1] = 2; x.value[0][2] = 3;
        x.value[1][0] = 4, x.value[1][1] = 5; x.value[1][2] = 6;
        x.value[2][0] = 7; x.value[2][1] = 8; x.value[2][2] = 9;
        x = MatPower(x, n - 1);
        ll ans = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ans = (ans + x.value[i][j]) % MOD;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}