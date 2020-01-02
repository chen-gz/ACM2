#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define N 200010
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set[N];
int n;
int a[N], b[N];
int a_pos[N], b_pos[N];

int read(int idx, int y1, int y2){
	int sum = 0;
	while(idx > 0){
		sum += order_set[idx].order_of_key(y2 + 1) - order_set[idx].order_of_key(y1);
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx, int y, int val){
	while(idx <= n + 1){
		if(val == 1)
			order_set[idx].insert(y);
		else if(val == -1)
			order_set[idx].erase(y);
		idx += (idx & -idx);
	}
}

int main(){
	int m;
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a_pos[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		b_pos[b[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		update(a_pos[i], b_pos[i], 1);
	}
	while(m--){
		int type;
		cin >> type;
		int la, lb, ra, rb;
		int x, y;
		if(type == 1){
			cin >> la >> ra >> lb >> rb;
			la--;
			int ans = read(ra, lb, rb) - read(la, lb, rb);
			cout << ans << endl;
		} else {
			cin >> x >> y;
			update(a_pos[b[x]], b_pos[b[x]], -1);
			update(a_pos[b[y]], b_pos[b[y]], -1);
			update(a_pos[b[x]], b_pos[b[y]], 1);
			update(a_pos[b[y]], b_pos[b[x]], 1);
			swap(b[x], b[y]);
			swap(b_pos[b[x]], b_pos[b[y]]);
		}
	}
	return 0;
}
