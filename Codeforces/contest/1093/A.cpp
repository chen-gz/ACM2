#include <iostream>
using namespace std;
int main ( int argc, char const *argv[] ) {
	int n;
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		int tmp;
		cin >> tmp;
		if ( tmp % 7 == 0 )
			cout << tmp / 7 << " ";
		else
			cout << tmp / 7 + 1 << " ";
	}
	return 0;
}
